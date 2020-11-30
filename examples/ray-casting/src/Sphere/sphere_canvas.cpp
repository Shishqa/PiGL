/*============================================================================*/
#include <GL/freeglut.h>

#include <cmath>
#include <cassert>

#include "Sphere/sphere_canvas.hpp"
#include "ShishGL/draw.hpp"
#include "ShishGL/vector3.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

SphereCanvas::SphereCanvas(const double& radius,
                           const Color& sphere_col,
                           const Color& floor_col,
                           const Color& light_col)
                                : Window(DEFAULT_WIN_SIZE)
                                , sphere_radius(radius)
                                , sphere_color(sphere_col)
                                , floor_color(floor_col)
                                , light_color(light_col) {}

/*----------------------------------------------------------------------------*/

Color SphereCanvas::dot_color(const double& x, const double& y,
                              const Vector3<double>& light_source_pos) {

    assert(sqrt(static_cast<double>(x * x) + static_cast<double>(y * y)) <=
        static_cast<double>(sphere_radius));

    double z = sqrt(sphere_radius * sphere_radius - x * x - y * y);

    /* random adjustment */
    Vector3<double> r_vector{x, y, z};
    Vector3<double> light_vector = light_source_pos - r_vector;

    double reflection_cos = cos(r_vector, light_vector);

    Vector3<double> reflection_vector = light_vector % (light_vector | r_vector);
    Vector3<double> camera_vector = camera_position - r_vector;

    double camera_cos = cos(reflection_vector, camera_vector);

    double diff_intensity = std::max(0.0, reflection_cos);
    double spec_intensity = std::pow(std::max(0.0, camera_cos), 25.0);

    return sphere_color * light_color * (diff_intensity) +
                          light_color * spec_intensity;
}

/*----------------------------------------------------------------------------*/

void SphereCanvas::onRender() {
    renderBegin(info.size);

    fillWithColor(floor_color);

    glTranslated(static_cast<double>(info.size.x) / 2.0,
                 static_cast<double>(info.size.y) / 2.0,
                 0.0);

    glLineWidth(1.0);

    glBegin(GL_POINTS);
    for (int y = static_cast<int>(-info.size.y) / 2;
         y < static_cast<int>(info.size.y) / 2; ++y) {
        for (int x = static_cast<int>(-info.size.x) / 2;
             x < static_cast<int>(info.size.x) / 2; ++x) {

            if (sqrt(static_cast<double>(x * x) + static_cast<double>(y * y)) >
                   static_cast<double>(sphere_radius)) {
                continue;
            }

            setColor(dot_color(x, y, light_source_position) +

                     dot_color(x, y, {-2 * sphere_radius, -sphere_radius, 0}) +
                     dot_color(x, y, {-2 * sphere_radius, -2 * sphere_radius, 100}) +
                     dot_color(x, y, {-2 * sphere_radius, -3 * sphere_radius, 200}) +
                     dot_color(x, y, {-2 * sphere_radius, -4 * sphere_radius, 300}) +

                     sphere_color * light_color * BG_LIGHT_INTENSITY);

            glVertex2i(static_cast<int>(x),
                       static_cast<int>(y));
        }
    }
    glEnd();
    renderEnd();
}

/*----------------------------------------------------------------------------*/

void SphereCanvas::onIdle() {

    source_angle += ANGLE_STEP;
    if (source_angle > 2 * M_PI) {
        source_angle = 0;
    }

    light_source_position.x = SOURCE_RADIUS * cos(source_angle);
    light_source_position.y = SOURCE_RADIUS * sin(source_angle);

    refresh();
}

/*============================================================================*/
