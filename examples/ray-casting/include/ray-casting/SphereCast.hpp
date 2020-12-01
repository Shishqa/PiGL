/*============================================================================*/
#ifndef RAY_CASTING_SPHERE_CAST_HPP
#define RAY_CASTING_SPHERE_CAST_HPP
/*============================================================================*/

#include "UICanvas.hpp"
#include "DefaultBehavior.hpp"
#include "Vector3.hpp"

/*============================================================================*/

class SphereCanvas : public Sh::UICanvas {
public:

    SphereCanvas(const Sh::Frame& frame,
                 const int64_t& radius,
                 const Sh::Color& sphere_color,
                 const Sh::Color& floor_color,
                 const Sh::Color& light_color);

    ~SphereCanvas() override = default;

private:

    friend class CanvasBehavior;

    void update();

    Sh::Vector3<double> camera_position{0, 0, 1000};
    Sh::Vector3<double> light_source_position{400, 0, -400};

    static constexpr double ANGLE_STEP = 0.05;
    static constexpr uint8_t BG_LIGHT_INTENSITY = 40;

    const double SOURCE_RADIUS = light_source_position.x;
    double source_angle = 0;

    const int64_t sphere_radius;

    Sh::Color sphere_color,
              floor_color,
              light_color;

    void onRender() override;

    Sh::Color dot_color(double x, double y,
                        const Sh::Vector3<double>& light_source_pos);

};

/*----------------------------------------------------------------------------*/

class CanvasBehavior : public Sh::DefaultBehavior {
public:

    explicit CanvasBehavior(Sh::UIWindow* target);

    bool onTimer(Sh::TimerEvent& event) override;

};

/*============================================================================*/
#endif //RAY_CASTING_SPHERE_CAST_HPP
/*============================================================================*/
