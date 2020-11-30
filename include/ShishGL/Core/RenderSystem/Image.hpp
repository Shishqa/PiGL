/*============================================================================*/
#ifndef SHISHGL_IMAGE_HPP
#define SHISHGL_IMAGE_HPP
/*============================================================================*/
#include <cstddef>
#include <vector>
#include <memory>
#include <immintrin.h>
#include <cstring>
#include <cassert>
#include <cstdlib>

#include "Color.hpp"
#include "ColorCollection.hpp"
#include "Vector2.hpp"
#include "IPlatform.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace ShishGL {

    class Image {
    public:

        using Pixels = std::vector<Color>;

        explicit Image(const Vector2<size_t>& size,
                       const Color& color = COLOR::WHITE)
                : img_size(size) {
            pixels.resize(size.x * size.y, color);
            assert(reinterpret_cast<uint64_t>(pixels.data()) % 32 == 0);
        }

        void fill(const Color& color) {
            pixels.assign(size().x * size().y, color);
        }

        void setPixel(const Vector2<size_t>& pos, const Color& color) {
            pixels[pos.y * img_size.x + pos.x] = color;
        }

        [[nodiscard]]
        const Color* getPixels() const {
            return pixels.data();
        }

        [[nodiscard]]
        const uint8_t* getData() const {
            return reinterpret_cast<const uint8_t*>(pixels.data());
        }

        [[nodiscard]]
        Color getPixel(size_t x, size_t y) const {
            return pixels[y * img_size.x + x];
        }

        [[nodiscard]]
        const Vector2<size_t>& size() const {
            return img_size;
        }

        void blend(const Image& other);

        void paste(IPlatform::IContext* context) {
            context->update(pixels.data());
        }

    private:

        Vector2<size_t> img_size;

        std::vector<Color> pixels;

    };

}
/*============================================================================*/
#endif //SHISHGL_IMAGE_HPP
/*============================================================================*/