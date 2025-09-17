#ifndef TEXT_HPP
#define TEXT_HPP

#include "paragraph.hpp"
#include "shape.hpp"
#include <string>

namespace Drawing
{
    class Text : public ShapeBase, private LegacyCode::Paragraph
    {
    public:
        static constexpr const char* id = "Text";

        Text(int x = 0, int y = 0, const std::string& text = "");

        void draw() const override;

        std::string content() const;

        void set_content(const std::string& text);
    };
}

#endif
