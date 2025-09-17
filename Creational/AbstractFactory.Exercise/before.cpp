#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

#define WINDOWS

enum class IconType
{
    none,
    ok,
    cancel,
    warning,
    error
};

class Widget
{
public:
    virtual void draw() = 0;
    virtual ~Widget() = default;
};

class Button : public Widget
{
    std::string caption_;
    IconType icon_type_;

public:
    Button(const std::string &caption, IconType icon_type)
        : caption_{caption}, icon_type_{icon_type}
    {
    }

    std::string caption() const
    {
        return caption_;
    }

    IconType icon() const
    {
        return icon_type_;
    }
};

class Menu : public Widget
{
    std::string text_;

public:
    Menu(const std::string &text)
        : text_{text}
    {
    }

    std::string text() const
    {
        return text_;
    }
};

class MotifButton : public Button
{
public:
    using Button::Button;

    void draw() override
    {
        cout << "MotifButton [ " << caption() << " ]\n";
    }
};

class MotifMenu : public Menu
{
public:
    using Menu::Menu;

    void draw() override
    {
        cout << "MotifMenu { " << text() << " }\n";
    }
};

class WindowsButton : public Button
{
public:
    using Button::Button;

    void draw() override
    {
        cout << "WindowsButton [ " << caption() << " ]\n";
    }
};

class WindowsMenu : public Menu
{
public:
    using Menu::Menu;

    void draw() override
    {
        cout << "WindowsMenu { " << text() << " }\n";
    }
};

class WidgetFactory
{
public:
    virtual std::unique_ptr<Button> create_button(const std::string &caption, IconType icon_type) = 0;
    virtual std::unique_ptr<Menu> create_menu(const std::string &text) = 0;
    virtual ~WidgetFactory() = default;
};

class MotifWidgetFactory : public WidgetFactory
{
    // WidgetFactory interface
public:
    std::unique_ptr<Button> create_button(const string &caption, IconType icon_type) override
    {
        return std::make_unique<MotifButton>(caption, icon_type);
    }

    std::unique_ptr<Menu> create_menu(const string &text) override
    {
        return std::make_unique<MotifMenu>(text);
    }
};

class WindowsWidgetFactory : public WidgetFactory
{
    // WidgetFactory interface
public:
    std::unique_ptr<Button> create_button(const string &caption, IconType icon_type) override
    {
        return std::make_unique<WindowsButton>(caption, icon_type);
    }

    std::unique_ptr<Menu> create_menu(const string &text) override
    {
        return std::make_unique<WindowsMenu>(text);
    }
};

class Window
{
    std::vector<std::unique_ptr<Widget>> widgets;

public:
    void display() const
    {
        std::cout << "######################\n";
        for (const auto &w : widgets)
            w->draw();
        std::cout << "######################\n\n";
    }

    void add_widget(std::unique_ptr<Widget> widget)
    {
        widgets.push_back(std::move(widget));
    }
};

class WindowOne : public Window
{

public:
    WindowOne(WidgetFactory &widget_factory)
    {
        // #ifdef MOTIF
        //         add_widget(std::make_unique<MotifButton>("OK", IconType::ok));
        //         add_widget(std::make_unique<MotifMenu>("File"));
        // #else // WINDOWS
        //         add_widget(std::make_unique<WindowsButton>("OK", IconType::ok));
        //         add_widget(std::make_unique<WindowsMenu>("File"));
        // #endif

        add_widget(widget_factory.create_button("OK", IconType::ok));
        add_widget(widget_factory.create_menu("File"));
    }
};

class WindowTwo : public Window
{

public:
    WindowTwo(WidgetFactory &widget_factory)
    {
// #ifdef MOTIF
//         add_widget(std::make_unique<MotifMenu>("Edit"));
//         add_widget(std::make_unique<MotifButton>("OK", IconType::ok));
//         add_widget(std::make_unique<MotifButton>("Cancel", IconType::cancel));
// #else // WINDOWS
//         add_widget(std::make_unique<WindowsMenu>("Edit"));
//         add_widget(std::make_unique<WindowsButton>("OK", IconType::ok));
//         add_widget(std::make_unique<WindowsButton>("Cancel", IconType::cancel));
// #endif

        add_widget(widget_factory.create_menu("Edit"));
        add_widget(widget_factory.create_button("OK", IconType::ok));
        add_widget(widget_factory.create_button("Cancel", IconType::cancel));
    }
};

int main(void)
{
#ifdef WINDOWS
    WindowsWidgetFactory widget_factory;
#else
    MotifWidgetFactory widget_factory;
#endif

    WindowOne w1(widget_factory);
    w1.display();

    WindowTwo w2(widget_factory);
    w2.display();
}
