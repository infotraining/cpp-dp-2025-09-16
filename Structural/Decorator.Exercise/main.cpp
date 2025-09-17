#include "starbugs_coffee.hpp"
#include <memory>
#include <cassert>

void client(std::unique_ptr<Coffee> coffee)
{
    std::cout << "Description: " << coffee->get_description() << "; Price: " << coffee->get_total_price() << std::endl;
    coffee->prepare();
}

class CoffeeBuilder
{
public:
    CoffeeBuilder() = default;

    template <typename TBase, typename... TArgs>
    CoffeeBuilder& create_base(TArgs&&... args)
    {
        coffee_ = std::make_unique<TBase>(std::forward<TArgs>(args)...);
        return *this;
    }

    template <typename... TDecorator>
    CoffeeBuilder& add()
    {
        assert(coffee_ && "Base coffee must be created first");
        (..., (coffee_ = std::make_unique<TDecorator>(std::move(coffee_))));
        return *this;
    }

    std::unique_ptr<Coffee> get_coffee()
    {
        return std::move(coffee_);
    }
private:
    std::unique_ptr<Coffee> coffee_;
};

int main()
{
    std::unique_ptr<Coffee> cf =
        std::make_unique<WhippedCream>(
            std::make_unique<Whisky>(
                std::make_unique<ExtraEspresso>(std::make_unique<Espresso>())));

    client(std::move(cf));

    CoffeeBuilder cb;

    cb.create_base<Espresso>()
      .add<Whisky>()
      .add<Whisky, ExtraEspresso, WhippedCream>();

    client(cb.get_coffee());
}
