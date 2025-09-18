#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

class Product;

// "Builder"
class CarBuilder
{
public:
    CarBuilder() = default;
    virtual ~CarBuilder() = default;

    // Template Method
    void construct()
    {
        reset();
        build_engine();
        build_gearbox();
        build_aircondition();
        build_wheels();
    }

protected:
    virtual void reset() = 0;
    virtual void build_engine() = 0;
    virtual void build_gearbox() = 0;
    virtual void build_aircondition() = 0;
    virtual void build_wheels() = 0;
};

// "Product"
class Car
{
    std::vector<std::string> parts_;

public:
    void add(const std::string &part)
    {
        parts_.push_back(part);
    }

    std::string get_configuration() const
    {
        using namespace std::literals;

        std::string description = "Car consists of:\n";

        for (const auto &part : parts_)
            description += " + "s + part + "\n"s;

        return description;
    }
};

// "ConcreteBuilder1"
class EconomyCarBuilder : public CarBuilder
{
public:
    EconomyCarBuilder()
    {
    }

    Car get_result()
    {
        return std::move(car_);
    }

private:
    Car car_;

protected:
    void reset() override
    {
        car_ = Car{};
    }

    void build_engine() override
    {
        car_.add("Petrol engine 1.1 l");
    }

    void build_gearbox() override
    {
        car_.add("Manual gearbox - 5 steps");
    }

    void build_aircondition() override
    {
    }

    void build_wheels() override
    {
        for (int i = 0; i < 4; ++i)
            car_.add("Wheel 16 inches - Regular tires");
    }
};

// "ConcreteBuilder2"
class PremiumCarBuilder : public CarBuilder
{
public:
    PremiumCarBuilder()
    {
    }

    Car get_result()
    {
        return std::move(car_);
    }

private:
    Car car_;

protected:
    void reset() override
    {
        car_ = Car{};
    }

    void build_engine() override
    {
        car_.add("Petrol engine v8 4.0");
    }

    void build_gearbox() override
    {
        car_.add("Automatic gearbox - 9 steps");
    }

    void build_aircondition() override
    {
        car_.add("Aircondition - 3 zones");
    }

    void build_wheels() override
    {
        for (int i = 0; i < 4; ++i)
            car_.add("Wheel 20 inches - Sport tires");
    }
};

#endif /*BUILDER_HPP_*/
