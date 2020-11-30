#ifndef SPHERE_RENDERING_SPHERE_CANVAS_HPP
#define SPHERE_RENDERING_SPHERE_CANVAS_HPP

#include "ShishGL/window.hpp"
#include "ShishGL/draw.hpp"
#include "ShishGL/vector3.hpp"

using namespace ShishGL;

class SphereCanvas : public Window {
public:

    SphereCanvas(const double& radius,
                 const Color& sphere_col,
                 const Color& floor_col,
                 const Color& light_col);

    ~SphereCanvas() override = default;

private:

    static constexpr Vector2<size_t> DEFAULT_WIN_SIZE = {800, 800};

    Vector3<double> camera_position{0, 0, 1000};
    Vector3<double> light_source_position{400, 0, -400};

    static constexpr double ANGLE_STEP = 0.05;
    static constexpr double BG_LIGHT_INTENSITY = 0.2;

    const double SOURCE_RADIUS = light_source_position.x;
    double source_angle = 0;

    const double sphere_radius;

    Color sphere_color,
          floor_color,
          light_color;

    void onRender() override;

    void onIdle() override;

    Color dot_color(const double& x, const double& y,
                    const Vector3<double>& light_source_pos);

};

#endif //SPHERE_RENDERING_SPHERE_CANVAS_HPP
