/*============================================================================*/
#ifndef SHISHGL_UI_TEXT_INPUT_HPP
#define SHISHGL_UI_TEXT_INPUT_HPP
/*============================================================================*/
#include <cctype>

#include "Clickable.hpp"
#include "KeyboardEvent.hpp"
#include "Styles.hpp"
/*============================================================================*/
namespace Sh {

    class TextField : public Clickable {
    public:

        explicit TextField(UIWindow* target, std::string& buf)
        : Clickable(target)
        , buffer(buf)
        , curr_pos(0) {
            SubscriptionManager::subscribe<KeyboardEvent>(this, EventSystem::SystemEvents);
        }

        void reactOnPress(MouseButtonEvent&) override {
            curr_active = target<UIWindow>();
        }

        bool onKeyboard(KeyboardEvent& event) override {

            if (target<UIWindow>() != curr_active) {
                return false;
            }

            if (event.state() == Keyboard::UP) {
                return false;
            }

            if (curr_pos < buffer.size() && Keyboard::isConvertible(event.key())) {

                char to_set = Keyboard::convertToChar(event.key());

                if (event.modifiers() & Keyboard::L_SHIFT_MOD) {
                    to_set = static_cast<char>(toupper(to_set));
                }

                buffer[curr_pos++] = to_set;
                return true;

            } else if (event.key() == Keyboard::BACKSPACE) {

                if (curr_pos) {
                    buffer[--curr_pos] = 0;
                }
                return true;

            }

            return false;
        }

    private:

        std::string& buffer;
        size_t curr_pos;

        static UIWindow* curr_active;
    };

    class BufferedTextField : public TextField {
    public:

        explicit BufferedTextField(UIWindow* target, size_t max_buf_size)
                : TextField(target, buffer) {
            buffer.resize(max_buf_size);
        }

        [[nodiscard]]
        const std::string& getBuffer() const {
            return buffer;
        }

        void setBuffer(const std::string_view& new_buffer) {
            buffer = new_buffer;
        }

    private:

        std::string buffer;
    };



}
/*============================================================================*/
#endif //SHISHGL_UI_TEXT_INPUT_HPP
/*============================================================================*/
