/*============================================================================*/
#ifndef SHISHGL_UI_TEXT_INPUT_HPP
#define SHISHGL_UI_TEXT_INPUT_HPP
/*============================================================================*/
#include <cctype>

#include "UILabel.hpp"
#include "Clickable.hpp"
#include "KeyboardEvent.hpp"
/*============================================================================*/
namespace Sh {

    class TextField : public Clickable {
    public:

        explicit TextField(UIWindow* target, char* input_buf,
                           size_t input_buf_size)
                : Clickable(target)
                , buf(input_buf)
                , buf_size(input_buf_size)
                , curr_pos(0) {
           SubscriptionManager::subscribe(this, EventSystem::SystemEvents,
                                          KEYBOARD);
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

            if (curr_pos < buf_size && Keyboard::isConvertible(event.key())) {

                char to_set = Keyboard::convertToChar(event.key());

                if (event.modifiers() & Keyboard::L_SHIFT_MOD) {
                    to_set = static_cast<char>(toupper(to_set));
                }

                buf[curr_pos++] = to_set;
                return true;

            } else if (event.key() == Keyboard::BACKSPACE) {

                if (curr_pos) {
                    buf[--curr_pos] = 0;
                }
                return true;

            } else if (curr_pos < buf_size) {

                buf[curr_pos++] = '*';

            }

            return false;
        }

    private:

        char* buf;
        size_t buf_size;
        size_t curr_pos;

        static UIWindow* curr_active;
    };

    class UITextInput : public UILabel {
    public:

        UITextInput(const Frame& frame, char* buffer, size_t buffer_size)
                : UILabel(frame, std::string_view(buffer, buffer_size)) {
            addBehavior<TextField>(buffer, buffer_size);
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_TEXT_INPUT_HPP
/*============================================================================*/
