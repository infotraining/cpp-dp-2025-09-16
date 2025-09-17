#include "text.hpp"
#include "shape_factories.hpp"

using namespace Drawing;

namespace
{
    bool is_registered = SingletonShapeFactory::instance()
        .register_creator(Text::id, [] { return std::make_unique<Text>(); });
}

Text::Text(int x, int y, const std::string& text)
    : ShapeBase{x, y}, LegacyCode::Paragraph(text.c_str())
{
}

void Text::draw() const
{
    render_at(coord().x, coord().y);
}

std::string Text::content() const
{
    return get_paragraph();
}

void Text::set_content(const std::string& text)
{
    set_paragraph(text.c_str());
}