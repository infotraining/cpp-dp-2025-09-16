#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

struct StatResult
{
    std::string description;
    double value;

    StatResult(const std::string &desc, double val)
        : description(desc), value(val)
    {
    }
};

using Data = std::vector<double>;
using Results = std::vector<StatResult>;

class Statistics
{
public:
    virtual ~Statistics() = default;
    virtual Results calculate(const Data &data) const = 0;
};

class Avg : public Statistics
{
public:
    Results calculate(const Data &data) const override
    {
        double sum = std::accumulate(data.begin(), data.end(), 0.0);
        double avg = sum / data.size();

        return {{"Avg", avg}};
    }
};

class MinMax : public Statistics
{
public:
    Results calculate(const Data &data) const override
    {
        Results results;

        double min = *(std::min_element(data.begin(), data.end()));
        double max = *(std::max_element(data.begin(), data.end()));

        results.push_back(StatResult("Min", min));
        results.push_back(StatResult("Max", max));

        return results;
    }
};

class StatGroup : public Statistics
{
    std::vector<std::shared_ptr<Statistics>> stats_;
public:
    Results calculate(const Data &data) const override
    {
        Results results;

        for(const auto& stat : stats_)
        {
            Results temp_result = stat->calculate(data);
            results.insert(results.end(), temp_result.begin(), temp_result.end());
        }

        return results;
    }

    void add_statistics(std::shared_ptr<Statistics> stat)
    {
        stats_.push_back(stat);
    }
};

class Sum : public Statistics
{
public:
    Results calculate(const Data &data) const override
    {
        double sum = std::accumulate(data.begin(), data.end(), 0.0);

        return {{"Sum", sum}};
    }
};

class DataAnalyzer
{
    std::shared_ptr<Statistics> statistics_;
    Data data_;
    Results results_;

public:
    DataAnalyzer(std::shared_ptr<Statistics> stat)
        : statistics_{stat}
    {
    }

    void load_data(const std::string &file_name)
    {
        data_.clear();
        results_.clear();

        std::ifstream fin(file_name.c_str());
        if (!fin)
            throw std::runtime_error("File not opened");

        double d;
        while (fin >> d)
        {
            data_.push_back(d);
        }

        std::cout << "File " << file_name << " has been loaded...\n";
    }

    void set_statistics(std::shared_ptr<Statistics> new_stat)
    {
        statistics_ = new_stat;
    }

    void calculate()
    {
        Results stat_results = statistics_->calculate(data_);
        results_.insert(results_.end(), stat_results.begin(), stat_results.end());
        // results_.append_range(stat_results); // C++23
    }

    const Results &results() const
    {
        return results_;
    }
};

void show_results(const Results &results)
{
    for (const auto &rslt : results)
        std::cout << rslt.description << " = " << rslt.value << std::endl;
}

int main()
{
    auto avg = std::make_shared<Avg>();
    auto min_max = std::make_shared<MinMax>();
    auto sum = std::make_shared<Sum>();

    auto std_stats = std::make_shared<StatGroup>();
    std_stats->add_statistics(min_max);
    std_stats->add_statistics(sum);
    
    auto adv_stats = std::make_shared<StatGroup>();
    adv_stats->add_statistics(std_stats);
    adv_stats->add_statistics(avg);

    DataAnalyzer da{std_stats};
    da.load_data("stats_data.dat");
    da.calculate();

    // da.set_statistics(min_max);
    // da.calculate();

    // da.set_statistics(sum);
    // da.calculate();

    show_results(da.results());

    std::cout << "\n\n";

    da.load_data("new_stats_data.dat");
    da.set_statistics(adv_stats);
    da.calculate();

    show_results(da.results());
}
