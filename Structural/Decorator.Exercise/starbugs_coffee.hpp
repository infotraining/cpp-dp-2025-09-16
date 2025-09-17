#ifndef COFFEEHELL_HPP_
#define COFFEEHELL_HPP_

#include <iostream>
#include <string>

class Coffee
{
public:
    virtual ~Coffee() = default;

    virtual float get_total_price() const = 0;
    virtual std::string get_description() const = 0;
    virtual void prepare() = 0;
};

class CoffeeBase : public Coffee
{
    float price_;
    std::string description_;

public:
    CoffeeBase(float price, const std::string& description) : price_{price}, description_{description}
    {
    }

    float get_total_price() const override
    {
        return price_;
    }

    std::string get_description() const override
    {
        return description_;
    }
};

class Espresso : public CoffeeBase
{
public:
    Espresso(float price = 4.0, const std::string& description = "Espresso")
        : CoffeeBase{price, description}
    {
    }

    void prepare() override
    {
        std::cout << "Making a perfect espresso: 7 g, 15 bar and 24 sec.\n";
    }
};

class Cappuccino : public CoffeeBase
{
public:
    Cappuccino(float price = 6.0, const std::string& description = "Cappuccino")
        : CoffeeBase{price, description}
    {
    }

    void prepare() override
    {
        std::cout << "Making a perfect cappuccino.\n";
    }
};

class Latte : public CoffeeBase
{
public:
    Latte(float price = 8.0, const std::string& description = "Latte")
        : CoffeeBase{price, description}
    {
    }

    void prepare() override
    {
        std::cout << "Making a perfect latte.\n";
    }
};

// TO DO: Condiments: Whipped: 2.5$, Whisky: 6.0$, ExtraEspresso: 4.0$

class CoffeeDecorator : public CoffeeBase
{
    std::unique_ptr<Coffee> coffee_;

public:
    CoffeeDecorator(std::unique_ptr<Coffee> coffee, float price, std::string desc)
        : CoffeeBase(price, desc), coffee_{move(coffee)}
    {
    }

    float get_total_price() const override
    {
        return CoffeeBase::get_total_price() + coffee_->get_total_price();
    }

    std::string get_description() const override
    {
        return coffee_->get_description() + " + " + CoffeeBase::get_description();
    }

    void prepare() override
    {
        coffee_->prepare();
    }
};

class WhippedCream : public CoffeeDecorator
{
public:
    WhippedCream(std::unique_ptr<Coffee> coffee, float price = 2.5, const std::string& desc = "Whipped Cream")
        : CoffeeDecorator(move(coffee), price, desc)
    {
    }

    void prepare() override
    {
        CoffeeDecorator::prepare();
        std::cout << "Adding a whipped cream..." << std::endl;
    }
};

class Whisky : public CoffeeDecorator
{
public:
    Whisky(std::unique_ptr<Coffee> coffee, float price = 6.0, const std::string& desc = "Whisky")
        : CoffeeDecorator(move(coffee), price, desc)
    {
    }

    void prepare() override
    {
        CoffeeDecorator::prepare();
        std::cout << "Pouring 5cl of whisky..." << std::endl;
    }
};

class ExtraEspresso : public CoffeeDecorator
{
public:
    ExtraEspresso(std::unique_ptr<Coffee> coffee, float price = 4.0, const std::string& desc = "Extra Espresso")
        : CoffeeDecorator(move(coffee), price, desc)
    {
    }

    void prepare() override
    {
        CoffeeDecorator::prepare();
        Espresso espresso;
        espresso.prepare();
    }
};

#endif /*COFFEEHELL_HPP_*/
