/*============================================================================*/
#ifndef SHISHGL_VECTOR_2_HPP
#define SHISHGL_VECTOR_2_HPP
/*============================================================================*/
namespace ShishGL {

    template <typename T>
    struct Vector2 {

        T x, y;

        T length() const;

        Vector2<T> operator-() const;

        Vector2<T> operator!() const;

        Vector2<T>& operator+=(const Vector2<T>& right);
        Vector2<T>  operator+ (const Vector2<T>& right) const;

        Vector2<T>& operator-=(const Vector2<T>& right);
        Vector2<T>  operator- (const Vector2<T>& right) const;

        Vector2<T>& operator*=(const T& mul);

        T operator^(const Vector2<T>& right) const;

        Vector2<T>& operator|=(const Vector2<T>& right);
        Vector2<T>  operator| (const Vector2<T>& right) const;

        template <typename P>
        explicit operator Vector2<P>() const;

    };

    template <typename T>
    Vector2<T> operator*(const T& mul, const Vector2<T>& vec);

}
/*============================================================================*/
#include "Vector2.ipp"
/*============================================================================*/
#endif //SHISHGL_VECTOR_2_HPP
/*============================================================================*/
