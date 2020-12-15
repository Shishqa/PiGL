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

    class Label : public Style {
    public:

        explicit Label(const std::string_view& label, const Color& font_color,
                       size_t font_size, Text::Align frame_align)
            : text(label)
            , color(font_color)
            , size(font_size)
            , align(frame_align)
            { }

        void apply(Frame& viewport, const Shape2D&) override {
            PLATFORM().setFontSize(size);
            PLATFORM().setColor(color);
            PLATFORM().displayText(text, viewport, align);
        }

    private:

        std::string_view text;
        Color color;
        size_t size;
        Text::Align align;
    };

    class StaticLabel : public Style {
    public:

        explicit StaticLabel(const std::string_view& label, const Color& font_color,
                       size_t font_size, Text::Align frame_align)
            : text(label)
            , color(font_color)
            , size(font_size)
            , align(frame_align)
        { }

        void apply(Frame& viewport, const Shape2D&) override {
            PLATFORM().setFontSize(size);
            PLATFORM().setColor(color);
            PLATFORM().displayText(text, viewport, align);
        }

    private:

        std::string text;
        Color color;
        size_t size;
        Text::Align align;
    };

}
/*============================================================================*/
#endif //SHISHGL_FONT_HPP
/*============================================================================*/
