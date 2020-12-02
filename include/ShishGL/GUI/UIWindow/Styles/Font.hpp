/*============================================================================*/
#ifndef SHISHGL_FONT_HPP
#define SHISHGL_FONT_HPP
/*============================================================================*/
#include <string_view>

#include "Style.hpp"
#include "RenderSystem.hpp"
#include "ResourceManager.hpp"
/*============================================================================*/
namespace Sh {

    class Font : public Style {
    public:

        explicit Font(const std::string_view& font_path)
                : path(font_path)
                { }

        void apply(Frame&, const Shape2D&) override {
            PLATFORM().setFont(ResourceManager::get(path));
        }

    private:

        std::string_view path;

    };

    class FontSize : public Style {
    public:

        explicit FontSize(const size_t& font_size)
                : size(font_size)
                { }

        void apply(Frame&, const Shape2D&) override {
            PLATFORM().setFontSize(size);
        }

    private:

        size_t size;

    };

}
/*============================================================================*/
#endif //SHISHGL_FONT_HPP
/*============================================================================*/
