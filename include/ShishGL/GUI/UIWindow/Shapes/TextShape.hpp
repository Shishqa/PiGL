/*============================================================================*/
#ifndef SHISHGL_TEXTSHAPE_HPP
#define SHISHGL_TEXTSHAPE_HPP
/*============================================================================*/
#include "Shape2D.hpp"
#include "Text.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace Sh {

    class TextShape : public Shape2D {
    public:

        explicit TextShape(const std::string_view& text,
                           IPlatform::Align text_align = IPlatform::Align::LEFT)
            : Shape2D()
            , s_text(text)
            , align(text_align)
            { }

        void draw(const Frame& frame) const override {
            //PLATFORM().displayText(s_text, frame, align);
        }

        [[nodiscard]]
        bool contains(const Frame&, const Vector2<double>&) const override {
            return true;
        }

    private:

        std::string_view s_text;
        IPlatform::Align align;
    };

}
/*============================================================================*/
#endif //SHISHGL_TEXTSHAPE_HPP
/*============================================================================*/
