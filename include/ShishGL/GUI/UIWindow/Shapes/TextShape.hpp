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

        explicit TextShape(const std::string_view& text)
            : Shape2D()
            , s_text(text)
            { }

        void draw(const Frame&) const override {
            //PLATFORM().displayText(s_text, viewport.pos);
        }

        [[nodiscard]]
        bool contains(const Frame&, const Vector2<double>&) const override {
            return true;
        }

    private:

        std::string_view s_text;
    };

}
/*============================================================================*/
#endif //SHISHGL_TEXTSHAPE_HPP
/*============================================================================*/
