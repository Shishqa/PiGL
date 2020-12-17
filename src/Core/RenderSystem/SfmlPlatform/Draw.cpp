/*============================================================================*/
#include "LogSystem.hpp"
#include "Platform.hpp"
#include "Image.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

SfmlPlatform::SfmlContext::SfmlContext(const Vector2<size_t>& size,
                                       const Color& color) {
    sf::Image img;
    img.create(
            static_cast<uint32_t>(size.x),
            static_cast<uint32_t>(size.y),
            sf::Color{color.r, color.g, color.b, color.a}
            );
    texture.loadFromImage(img);
}

SfmlPlatform::SfmlContext::SfmlContext(const std::string_view& filename) {
    texture.loadFromFile(filename.data());
}

Vector2<size_t> SfmlPlatform::SfmlContext::getSize() {
    return Vector2<size_t>{texture.getSize().x,
                           texture.getSize().y};
}

void SfmlPlatform::SfmlContext::update(const Color* data) {
    texture.update(reinterpret_cast<const uint8_t*>(data));
}

void SfmlPlatform::SfmlContext::updateAt(const Vector2<size_t>& pos,
                                         const Color& color) {
    texture.update(reinterpret_cast<const uint8_t*>(&color),
                   1, 1, static_cast<uint32_t>(pos.x),
                   static_cast<uint32_t>(pos.y));
}

void SfmlPlatform::SfmlContext::paste(Image& image) {

    auto sf_image = texture.copyToImage();
    image.resize({sf_image.getSize().x, sf_image.getSize().y});

    for (size_t x = 0; x < sf_image.getSize().x; ++x) {
        for (size_t y = 0; y < sf_image.getSize().y; ++y) {
            sf::Color sf_color = sf_image.getPixel(x, y);
            image.setPixel({x, y}, Color(sf_color.r, sf_color.g,
                                         sf_color.b, sf_color.a));
        }
    }
}


/*----------------------------------------------------------------------------*/

IPlatform::IContext* SfmlPlatform::createContext(const Vector2<size_t>& size,
                                                 const Color& color) {
    return new SfmlContext(size, color);
}

IPlatform::IContext* SfmlPlatform::loadContextFromImage(const std::string_view& filename) {
    return new SfmlContext(filename);
}

void SfmlPlatform::saveContextAsImage(IContext* context, const std::string_view& filename) {

    auto sfml_context = dynamic_cast<SfmlContext*>(context);
    if (!sfml_context) {
        return;
    }

    sf::Image img = sfml_context->texture.copyToImage();

    img.saveToFile(filename.data());
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::setViewport(const Frame& frame) {

    sf::View view(sf::FloatRect{
            static_cast<float>(frame.pos.x),
            static_cast<float>(frame.pos.y),
            static_cast<float>(frame.size.x),
            static_cast<float>(frame.size.y)
    });

    view.setViewport(sf::FloatRect{
            static_cast<float>(frame.pos.x / display_size.x),
            static_cast<float>(frame.pos.y / display_size.y),
            static_cast<float>(frame.size.x / display_size.x),
            static_cast<float>(frame.size.y / display_size.y)
    });

    canvas->setView(view);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::setColor(const Color& color) {
    active_color = color;
    active_texture = nullptr;
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::setTexture(const ResourceManager::Resource& texture) {

    if (textures.count(texture.filename)) {
        active_texture = textures[texture.filename];
        return;
    }

    auto sf_texture = new sf::Texture;
    sf_texture->loadFromMemory(texture.data, texture.size);

    textures[texture.filename] = sf_texture;
    active_texture = sf_texture;
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::drawPoint(const Vector2<double>& pos) {

    sf::VertexArray point(sf::Points, 1);

    point[0].position = sf::Vector2f(static_cast<float>(pos.x),
                                     static_cast<float>(pos.y));
    point[0].color = sf::Color(active_color.r,
                               active_color.g,
                               active_color.b,
                               active_color.a);

    canvas->draw(point);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::drawLine(const Vector2<double>& start,
                          const Vector2<double>& end) {

    sf::VertexArray line(sf::LineStrip, 2);

    line[0].position = sf::Vector2f(static_cast<float>(start.x),
                                    static_cast<float>(start.y));
    line[0].color = sf::Color(active_color.r,
                              active_color.g,
                              active_color.b,
                              active_color.a);

    line[1].position = sf::Vector2f(static_cast<float>(end.x),
                                    static_cast<float>(end.y));
    line[1].color = sf::Color(active_color.r,
                              active_color.g,
                              active_color.b,
                              active_color.a);

    canvas->draw(line);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::drawRectangle(const Vector2<double>& pos,
                               const Vector2<double>& size) {

    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(static_cast<float>(size.x),
                                   static_cast<float>(size.y)));
    rectangle.setPosition(sf::Vector2f(static_cast<float>(pos.x),
                                       static_cast<float>(pos.y)));

    if (active_texture) {

        rectangle.setTexture(active_texture);

    } else {

        rectangle.setFillColor(sf::Color{
                active_color.r,
                active_color.g,
                active_color.b,
                active_color.a
        });
    }

    canvas->draw(rectangle);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::drawCircle(const Vector2<double>& pos,
                            const double& radius) {

    sf::CircleShape circle;

    circle.setPosition(sf::Vector2f(static_cast<float>(pos.x),
                                    static_cast<float>(pos.y)));
    circle.setRadius(static_cast<float>(radius));

    if (active_texture) {

        circle.setTexture(active_texture);

    } else {

        circle.setFillColor(sf::Color{
                active_color.r,
                active_color.g,
                active_color.b,
                active_color.a
        });
    }

    canvas->draw(circle);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::displayContext(const IPlatform::IContext* context,
                                  const Vector2<double>& pos) {

    auto sfml_image = dynamic_cast<const SfmlContext*>(context);
    if (!sfml_image) {
        return;
    }

    sf::Sprite sprite(sfml_image->texture);
    sprite.setPosition(
            static_cast<float>(pos.x),
            static_cast<float>(pos.y)
            );

    canvas->draw(sprite);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::setFont(const ResourceManager::Resource& font) {

    if (fonts.count(font.filename)) {
        active_font = fonts[font.filename];
        return;
    }

    auto sf_font = new sf::Font;
    sf_font->loadFromMemory(font.data, font.size);

    fonts[font.filename] = sf_font;
    active_font = sf_font;
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::setFontSize(const size_t& font_sz) {
    font_size = font_sz;
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::displayText(const std::string_view& text,
                               const Frame& frame,
                               Text::Align align) {
#ifndef NO_SFML_TEXT
    if (!active_font) {
        return;
    }

    sf::Text display_text(sf::String{text.data()}, *active_font,
                          static_cast<unsigned int>(font_size));

    display_text.setFillColor(sf::Color{
            active_color.r,
            active_color.g,
            active_color.b,
            active_color.a
    });

    if (align == Text::LEFT) {

        display_text.setPosition(
                sf::Vector2f{
                        static_cast<float>(frame.pos.x),
                        static_cast<float>(frame.pos.y)
                        }
                );

    } else if (align == Text::CENTER) {

        display_text.setPosition(
                sf::Vector2f{
                        static_cast<float>(frame.pos.x + frame.size.x / 2 -
                                           display_text.getLocalBounds().width / 2),
                        static_cast<float>(frame.pos.y)
                }
        );

    } else {

        display_text.setPosition(
                sf::Vector2f{
                        static_cast<float>(frame.pos.x + frame.size.x -
                                           display_text.getLocalBounds().width),
                        static_cast<float>(frame.pos.y)
                }
        );
    }

    canvas->draw(display_text);
#endif
}

/*============================================================================*/
