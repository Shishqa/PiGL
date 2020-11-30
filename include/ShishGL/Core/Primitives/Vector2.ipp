/*============================================================================*/
#ifndef SHISHGL_VECTOR2_IPP
#define SHISHGL_VECTOR2_IPP
/*============================================================================*/
#include <cmath>
/*============================================================================*/
namespace Sh {

    template <typename T>
    T Vector2<T>::length() const {
        return sqrt(*this ^ *this);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    template <typename P>
    Vector2<T>::operator Vector2<P>() const {
        return Vector2<P>{
                static_cast<P>(x),
                static_cast<P>(y)
        };
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T> Vector2<T>::operator-() const {
        return Vector2<T>{-x, -y};
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& right) {
        x += right.x;
        y += right.y;
        return *this;
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator+(const Vector2<T>& right) const {
        return (Vector2<T>{*this} += right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& right) {
        return (*this += (-right));
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2<T>& right) const {
        return (Vector2<T>{*this} -= right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T>& Vector2<T>::operator*=(const T& mul) {
        x *= mul;
        y *= mul;
        return *this;
    }

    template <typename T>
    Vector2<T> operator*(const T& mul, const Vector2<T>& vec) {
        return (Vector2<T>{vec} *= mul);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    T Vector2<T>::operator^(const Vector2<T>& right) const {
        return x * right.x + y * right.y;
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T>& Vector2<T>::operator|=(const Vector2<T> &right) {
        *this = ((*this ^ right) / (right ^ right)) * right;
        return *this;
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator|(const Vector2<T>& right) const {
        return (Vector2<T>{*this} |= right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T> Vector2<T>::operator!() const {
        return *this;
    }

}
/*============================================================================*/
#endif //SHISHGL_VECTOR2_IPP
/*============================================================================*/
