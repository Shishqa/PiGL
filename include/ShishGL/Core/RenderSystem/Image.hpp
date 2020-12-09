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
#include "Vector2.hpp"
#include "IPlatform.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace Sh {

    class Image {
    public:

        using Pixels = std::vector<Color>;

        explicit Image(const Vector2<size_t>& size,
                       const Color& color = Color::WHITE);

        ~Image();

        void fill(const Color& color);

        /*--------------------------------------------------------------------*/

        void setPixel(const Vector2<size_t>& pos, const Color& color);

        [[nodiscard]]
        Color getPixel(const Vector2<size_t>& pos) const;

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Color* getPixels() const;

        [[nodiscard]]
        uint8_t* getData() const;

        [[nodiscard]]
        const Vector2<size_t>& size() const;

        /*--------------------------------------------------------------------*/

        void blend(const Image& other);

        void paste(IPlatform::IContext* context);

    private:

        Vector2<size_t> img_size;

        Color* pixels;
    };

}
/*============================================================================*/
#endif //SHISHGL_IMAGE_HPP
/*============================================================================*/