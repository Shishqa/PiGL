/*============================================================================*/
#include <cmath>
#include <cassert>

#include "SphereCast.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

SphereCanvas::SphereCanvas(const Frame& frame,
                           const int64_t& radius,
                           const Color& sphere_col,
                           const Color& floor_col,
                           const Color& light_col)
        : Sh::UICanvas(frame)
        , sphere_radius(radius)
        , sphere_color(sphere_col)
        , floor_color(floor_col)
        , light_color(light_col)
        { }

/*----------------------------------------------------------------------------*/

Color SphereCanvas::dot_color(double x, double y,
                              const Vector3<double>& light_source_pos) {

    auto r = static_cast<double>(sphere_radius);
    double r2 = r * r;

    x += r;
    y += r;

    double z = sqrt(r2 - x * x - y * y);

    /* random adjustment */
    Vector3<double> r_vector{x, y, z};
    Vector3<double> light_vector = light_source_pos - r_vector;

    double reflection_cos = cos(r_vector, light_vector);

    Vector3<double> reflection_vector = light_vector % (light_vector | r_vector);
    Vector3<double> camera_vector = camera_position - r_vector;

    double camera_cos = cos(reflection_vector, camera_vector);

    double diff_intensity = std::max(0.0, reflection_cos) * 255;
    double spec_intensity = std::pow(std::max(0.0, camera_cos), 25.0) * 255;

    return sphere_color * light_color * (static_cast<uint8_t>(diff_intensity)) +
                          light_color *  static_cast<uint8_t>(spec_intensity);
}

/*----------------------------------------------------------------------------*/

void SphereCanvas::onRender() {

    UICanvas::onRender();

}

void SphereCanvas::update() {

    source_angle += ANGLE_STEP;
    if (source_angle > 2 * M_PI) {
        source_angle = 0;
    }

    light_source_position.x = SOURCE_RADIUS * cos(source_angle);
    light_source_position.y = SOURCE_RADIUS * sin(source_angle);

    canvas.fill(floor_color);

    for (int64_t y = 0; y < static_cast<int64_t>(canvas.size().y); ++y) {
        for (int64_t x = 0; x < static_cast<int64_t>(canvas.size().x); ++x) {

            if ((x - sphere_radius) * (x - sphere_radius) +
                (y - sphere_radius) * (y - sphere_radius) >
                sphere_radius * sphere_radius) {
                continue;
            }

            auto double_x = static_cast<double>(x);
            auto double_y = static_cast<double>(y);
            auto double_r = static_cast<double>(sphere_radius);

            canvas.setPixel({static_cast<size_t>(x), static_cast<size_t>(y)},

                            dot_color(double_x, double_y, light_source_position) +

                            dot_color(double_x, double_y, {-2 * double_r, -double_r, 0}) +
                            dot_color(double_x, double_y, {-2 * double_r, -2 * double_r, 100.0}) +
                            dot_color(double_x, double_y, {-2 * double_r, -3 * double_r, 200}) +
                            dot_color(double_x, double_y, {-2 * double_r, -4 * double_r, 300}) +

                            sphere_color * light_color * BG_LIGHT_INTENSITY);
        }
    }

}

/*----------------------------------------------------------------------------*/

CanvasBehavior::CanvasBehavior(Sh::UIWindow* target)
        : Sh::DefaultBehavior(target)
        {
    SubscriptionManager::subscribe(EventSystem::SystemEvents, this,
                                   TIMER);
        }


bool CanvasBehavior::onTimer(Sh::TimerEvent &event) {
    target<SphereCanvas>()->update();
    return true;
}

/*============================================================================*/
