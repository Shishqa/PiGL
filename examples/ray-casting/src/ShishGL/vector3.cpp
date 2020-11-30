#include "ShishGL/vector3.hpp"

#include <cmath>

using namespace ShishGL;

template <>
Vector3<double> Vector3<double>::operator!() const {
    double len = sqrt(x * x + y * y + z * z);
    return Vector3<double>{x / len, y / len, z / len};
}

double ShishGL::cos(const Vector3<double>& v1, const Vector3<double>& v2) {
    return (v1^v2) / sqrt((v1^v1) * (v2^v2));
}
