#include "strategy.hpp"

    auto capitalize_formatter = [](const std::string &data) -> std::string {
            std::string transformed_data{data};

            if (data.size() >= 1)
            {
                transformed_data[0] = static_cast<char>(std::toupper(data.front()));

                std::transform(data.begin() + 1, data.end(), transformed_data.begin() + 1, [](char c)
                               { return std::tolower(c); });
            }

            return transformed_data;
        };

int main()
{
    DataContext data{UpperCaseFormatter{}};
    data.pretty_print();

    auto lcf = LowerCaseFormatter();
    data.reset_formatter(lcf);
    data.pretty_print();

    data.reset_formatter(capitalize_formatter);
    data.pretty_print();
}
