/*============================================================================*/
#include <cstdlib>
#include <nmmintrin.h>
#include <sys/types.h>

#include <stdexcept>

#include "Image.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

Image::Image(const Vector2<size_t>& size, const Color& color)
    : img_size(size) {

    pixels = new Color[size.x * size.y];
    fill(color);
}

/*----------------------------------------------------------------------------*/

Image::~Image() {
    delete[] pixels;
}

/*----------------------------------------------------------------------------*/

void Image::resize(const Vector2<size_t>& new_size,
                   const Color& color) {
    delete[] pixels;
    img_size = new_size;

    pixels = new Color[img_size.x * img_size.y];
    fill(color);
}

/*----------------------------------------------------------------------------*/

void Image::fill(const Color& color) {
    for (size_t i = 0; i < img_size.x * img_size.y; ++i) {
        pixels[i] = color;
    }
}

/*----------------------------------------------------------------------------*/

void Image::setPixel(const Vector2<size_t>& pos, const Color& color) {
    pixels[pos.y * img_size.x + pos.x] = color;
}

/*----------------------------------------------------------------------------*/

const Color* Image::getPixels() const {
    return pixels;
}

/*----------------------------------------------------------------------------*/

uint8_t* Image::getData() const {
    return reinterpret_cast<uint8_t*>(pixels);
}

/*----------------------------------------------------------------------------*/

Color Image::getPixel(const Vector2<size_t>& pos) const {
    return pixels[pos.y * img_size.x + pos.x];
}

/*----------------------------------------------------------------------------*/

const Vector2<size_t>& Image::size() const {
    return img_size;
}

/*----------------------------------------------------------------------------*/

void Image::paste(IPlatform::IContext* context) {
    context->update(pixels);
}

/*----------------------------------------------------------------------------*/

void Image::blend(const Image& other) {

    const size_t WIDTH = size().x;
    const size_t HEIGHT = size().y;

    if (WIDTH != other.size().x || HEIGHT != other.size().y) {
        throw std::runtime_error("blending images of different sizes");
    }

    const auto front = reinterpret_cast<const uint32_t*>(other.getData());
    auto back = reinterpret_cast<uint32_t*>(getData());

    unsigned int alpha_mask = 0xFF000000;
    unsigned short alpha = 0x00;

    unsigned short tmp = 0x0000;

    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            alpha = (front[y * HEIGHT + x] & alpha_mask) >> 24;

            for (unsigned int mask = 0x000000FF, i = 0; i < 4; mask <<= 8, ++i) {

                tmp = ((front[y * HEIGHT + x] & mask) >> 8 * i) * static_cast<unsigned short>(alpha);
                tmp += ((back[y * HEIGHT + x] & mask) >> 8 * i) * static_cast<unsigned short>(255 - alpha);
                tmp >>= 8;
        
                back[y * HEIGHT + x] &= (UINT32_MAX - mask); 
                back[y * HEIGHT + x] |= (tmp << 8 * i);
            }
        }
    }

/*     const Color* front = other.getPixels(); */
/*     Color* back = pixels; */

/*     const char X = static_cast<char>(0x80); */
/*     const char F = static_cast<char>(0xFF); */

/*     const __m128i C255 = _mm_set_epi8(0, F, 0, F, 0, F, 0, F, 0, F, 0, F, 0, F, 0, F); */

/*     for (size_t i = 0; i < size().x * size().y; i += 4) { */

/*         __m128i front_l = _mm_load_si128(reinterpret_cast<const __m128i*>(front + i)); */
/*         __m128i back_l = _mm_load_si128(reinterpret_cast<const __m128i*>(back + i)); */

/*         __m128i shuffle_high_to_low = _mm_set_epi8(X, X, X, X, X, X, X, X, 15, 14, 13, 12, 11, 10, 9, 8); */

/*         __m128i front_h = _mm_shuffle_epi8(front_l, shuffle_high_to_low); */
/*         __m128i back_h = _mm_shuffle_epi8(back_l, shuffle_high_to_low); */

/*         front_l = _mm_cvtepi8_epi16(front_l); */
/*         front_h = _mm_cvtepi8_epi16(front_h); */

/*         back_l = _mm_cvtepi8_epi16(back_l); */
/*         back_h = _mm_cvtepi8_epi16(back_h); */

/*         __m128i alpha_mask = _mm_set_epi8(X,14,X,14,X,14,X,14,X,6,X,6,X,6,X,6); */

/*         __m128i front_alpha_l = _mm_shuffle_epi8(front_l, alpha_mask); */
/*         __m128i front_alpha_h = _mm_shuffle_epi8(front_h, alpha_mask); */

/*         front_l = _mm_mullo_epi16(front_l, front_alpha_l); */
/*         front_h = _mm_mullo_epi16(front_h, front_alpha_h); // front *= alpha */

/*         back_l = _mm_mullo_epi16(back_l, _mm_sub_epi16(C255, front_alpha_l)); */
/*         back_h = _mm_mullo_epi16(back_h, _mm_sub_epi16(C255, front_alpha_h));  // back *= (255 - alpha) */

/*         __m128i sum_l = _mm_add_epi16(front_l, back_l); */
/*         __m128i sum_h = _mm_add_epi16(front_h, back_h);                  // sum = front + back */

/*         __m128i shuffle_sum_l_mask = _mm_set_epi8(X, X, X, X, X, X, X, X, 15, 13, 11, 9, 7, 5, 3, 1); */

/*         sum_l = _mm_shuffle_epi8(sum_l, shuffle_sum_l_mask); */

/*         __m128i shuffle_sum_h_mask = _mm_set_epi8(15, 13, 11, 9, 7, 5, 3, 1, X, X, X, X, X, X, X, X); */

/*         sum_h = _mm_shuffle_epi8(sum_h, shuffle_sum_h_mask); */

/*         __m128i res = _mm_or_si128(sum_h, sum_l); */

/*         _mm_storeu_si128(reinterpret_cast<__m128i*>(back + i), res); */
/*     } */
}



/*============================================================================*/
