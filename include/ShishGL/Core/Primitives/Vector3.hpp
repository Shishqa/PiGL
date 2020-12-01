/*============================================================================*/
#ifndef SHISHGL_VECTOR3_HPP
#define SHISHGL_VECTOR3_HPP
/*============================================================================*/

#include <cmath>
#include <ostream>

/*============================================================================*/

namespace Sh {

    template <typename T>
    struct Vector3 {
        T x, y, z;

        /* normalize */
        Vector3<T>  operator!() const;

        /* projection */
        Vector3<T>  operator|(const Vector3<T>& right) const;
        Vector3<T>& operator|=(const Vector3<T>& right);

        /* reflection relative to the right vector along
         * the guideline connecting the ends */
        Vector3<T>  operator%(const Vector3<T>& right) const;
        Vector3<T>& operator%=(const Vector3<T>& right);

        Vector3<T>  operator+(const Vector3<T>& right) const;
        Vector3<T>& operator+=(const Vector3<T>& right);

        Vector3<T>  operator-() const;

        Vector3<T>  operator-(const Vector3<T>& right) const;
        Vector3<T>& operator-=(const Vector3<T>& right);

        Vector3<T>  operator*(const T& mul) const;
        Vector3<T>& operator*=(const T& mul);

        /* dot multiplication */
        T operator^(const Vector3<T>& right) const;
    };

    /*------------------------------------------------------------------------*/

    double cos(const Vector3<double>& v1, const Vector3<double>& v2);

    /*------------------------------------------------------------------------*/

    template <typename T>
    std::ostream& operator<<(std::ostream& out, const Vector3<T>& vec) {
        out << "(" << vec.x << "; " << vec.y << "; " << vec.z << ")";
        return out;
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector3<T> Vector3<T>::operator-() const {
        return Vector3<T>{-x, -y, -z};
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector3<T> Vector3<T>::operator!() const {
        return *this;
    }

    template <>
    Vector3<double> Vector3<double>::operator!() const;

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector3<T>& Vector3<T>::operator%=(const Vector3<T>& right) {
        *this += (right - *this) * 2;
        return *this;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator%(const Vector3<T>& right) const {
        return (Vector3<T>{*this} %= right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector3<T>& Vector3<T>::operator|=(const Vector3<T>& right) {
        *this = right * ((*this ^ right) / (right ^ right));
        return *this;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator|(const Vector3<T>& right) const {
        return (Vector3<T>{*this} |= right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& right) {
        x += right.x;
        y += right.y;
        z += right.z;
        return *this;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator+(const Vector3<T>& right) const {
        return (Vector3<T>{*this} += right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& right) {
        return (&this += (-right));
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator-(const Vector3<T>& right) const {
        return Vector3<T>{*this} + (-right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector3<T>& Vector3<T>::operator*=(const T& mul) {
        x *= mul; y *= mul; z *= mul;
        return *this;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator*(const T& mul) const {
        return (Vector3<T>{*this} *= mul);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    T Vector3<T>::operator^(const Vector3<T>& right) const {
        return (x * right.x + y * right.y + z * right.z);
    }

    /*------------------------------------------------------------------------*/
}

/*============================================================================*/
#endif //SHISHGL_VECTOR3_HPP
/*============================================================================*/
