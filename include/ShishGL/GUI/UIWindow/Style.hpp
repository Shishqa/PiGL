/*============================================================================*/
#ifndef SHISHGL_STYLE_HPP
#define SHISHGL_STYLE_HPP
/*============================================================================*/
#include <vector>

#include "Shape2D.hpp"
#include "Viewport.hpp"
/*============================================================================*/
namespace Sh {

    class Style {
    public:

        Style() = default;

        virtual void apply(Viewport& viewport, const Shape2D& shape) = 0;

        virtual ~Style() = default;

    };

    /*-------------------------------------------------------------------------*/

    class StylePack : public Style {
    public:

        StylePack() = default;

        template <typename... Args>
        explicit StylePack(Args&&... args) {
            add(std::forward<Args>(args)...);
        }

        void apply(Viewport& viewport, const Shape2D& shape) override {
            for (auto& style : styles) {
                style->apply(viewport, shape);
            }
        }

        ~StylePack() override {
            for (auto& style : styles) {
                delete style;
            }
        }

        template <typename SomeStyle, typename... Args>
        void add(const SomeStyle& style, Args&&... args) {
            add(style);
            add(std::forward<Args>(args)...);
        }

        template <typename SomeStyle>
        void add(const SomeStyle& style) {
            auto* new_style = new SomeStyle(style);
            styles.emplace_back(new_style);
        }

    private:

        std::vector<Style*> styles;

    };

}
/*============================================================================*/
#endif //SHISHGL_STYLE_HPP
/*============================================================================*/
