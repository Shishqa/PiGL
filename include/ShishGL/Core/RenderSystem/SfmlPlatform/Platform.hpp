/*============================================================================*/
#ifndef SHISHGL_SFML_PLATFORM_HPP
#define SHISHGL_SFML_PLATFORM_HPP
/*============================================================================*/
#include <cstddef>
#include <string_view>

#include <SFML/Graphics.hpp>

#include "IPlatform.hpp"
/*============================================================================*/
namespace Sh {

    class SfmlPlatform : public IPlatform {
    public:

        SfmlPlatform();

        bool isRunning() override;

        /* Input */
        /*--------------------------------------------------------------------*/
        Vector2<double> getMousePos() override;
        /*--------------------------------------------------------------------*/

        /* View */
        /*--------------------------------------------------------------------*/
        void setViewport(const Frame& frame) override;

        const Vector2<double>& getDisplaySize() override;
        /*--------------------------------------------------------------------*/

        /* Draw */
        /*--------------------------------------------------------------------*/
        class SfmlContext : public IContext {
        public:

            explicit SfmlContext(const Vector2<size_t>& size,
                                 const Color& color);

            explicit SfmlContext(const std::string_view& filename);

            Vector2<size_t> getSize() override;

            void update(const Color* data) override;

            void updateAt(const Vector2<size_t>& pos,
                          const Color& color) override;

            void paste(class Image &image) override;

            ~SfmlContext() override = default;

        private:

            sf::Texture texture;

            friend class SfmlPlatform;
        };

        IContext* createContext(const Vector2<size_t>& size,
                                const Color& color) override;

        IContext* loadContextFromImage(const std::string_view& filename) override;

        void saveContextAsImage(IContext* context, const std::string_view& filename) override;

        /*--------------------------------------------------------------------*/
        void setColor(const Color& color) override;

        void setTexture(const ResourceManager::Resource& texture) override;

        void drawPoint(const Vector2<double>& pos) override;

        void drawLine(const Vector2<double>& start,
                      const Vector2<double>& end) override;

        void drawRectangle(const Vector2<double>& pos,
                           const Vector2<double>& size) override;

        void drawCircle(const Vector2<double>& pos,
                        const double& radius) override;
        /*--------------------------------------------------------------------*/

        /* Image */
        /*--------------------------------------------------------------------*/
        void displayContext(const IPlatform::IContext* context,
                            const Vector2<double>& pos) override;

        /* Text */
        /*--------------------------------------------------------------------*/
        void setFont(const ResourceManager::Resource& font) override;

        void setFontSize(const size_t& font_size) override;

        void displayText(const std::string_view& text,
                         const Frame& frame,
                         Text::Align align) override;
        /*--------------------------------------------------------------------*/


        ~SfmlPlatform() override = default;

    protected:

        /* Essential */
        /*--------------------------------------------------------------------*/
         bool initDisplay(int* argc_ptr, char* argv[]) override;

         bool closeDisplay() override;
        /*--------------------------------------------------------------------*/

        /* Rendering */
        /*--------------------------------------------------------------------*/
         void clear(const Color& color) override;

         void display() override;
        /*--------------------------------------------------------------------*/

        /* Events */
        /*--------------------------------------------------------------------*/
         bool pollEvent() override;
        /*--------------------------------------------------------------------*/

    private:

        /* IMPLEMENTATION SPECIAL */
        /*====================================================================*/

        Vector2<double> display_size;

        bool is_running;

        sf::RenderWindow* canvas;

        Color active_color;

        sf::Texture* active_texture;
        std::unordered_map<std::string_view, sf::Texture*> textures;

        sf::Font* active_font;
        std::unordered_map<std::string_view, sf::Font*> fonts;

        size_t font_size;

    };

}
/*============================================================================*/
#endif //SHISHGL_SFML_PLATFORM_HPP
/*============================================================================*/
