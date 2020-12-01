/*============================================================================*/
#ifndef SHISHGL_TEXTURE_FILL_HPP
#define SHISHGL_TEXTURE_FILL_HPP
/*============================================================================*/
#include <string_view>

#include "Style.hpp"
#include "ResourceManager.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace Sh {

    class TextureFill : public Style {
    public:

        explicit TextureFill(const std::string_view& filename)
                : file(filename) {
            ResourceManager::load(file);
        }

        void apply(Frame& frame, const Shape2D& shape) override {
            PLATFORM().setTexture(ResourceManager::get(file));
            shape.draw(frame);
        }

        ~TextureFill() override = default;

    private:

        const std::string_view file;

    };

}
/*============================================================================*/
#endif //SHISHGL_TEXTURE_FILL_HPP
/*============================================================================*/
