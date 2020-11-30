#ifndef DRAW_HPP
#define DRAW_HPP


#include <cstdint>
#include <cstddef>
#include <string_view>

#include "essential.hpp"
#include "colors.hpp"


namespace ShishGL {

    struct Color {
        uint8_t r, g, b, a;

        /* cut value if it is greater than UINT8_MAX */
        static uint8_t normalize(const double& channel);

        /* each channel (r, g, b) is multiplied by intensity */
        Color& operator*=(const double& intensity);
        Color operator*(const double& intensity);

        /* by-channel multiplying */
        Color& operator*=(const Color& right);
        Color operator*(const Color& right);

        /* by-channel sum */
        Color& operator+=(const Color& right);
        Color operator+(const Color& right);
    };

    void renderBegin(const Vector2<double>& viewport);
    void renderBegin(const Vector2<size_t>& viewport);

    void renderEnd();

    void fillWithColor(const Color& color);

    void setColor(const Color& color);

    size_t displayText(const std::string_view& text,
                       const Vector2<double>& position,
                       const Color& color);

    void drawLine(const Vector2<double>& begin,
                  const Vector2<double>& end);

    void drawArrow(const Vector2<double>& begin,
                   const Vector2<double>& end);

}


#endif //DRAW_HPP
