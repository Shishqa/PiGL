/*============================================================================*/
#ifndef SHISHGL_UISELECTLIST_HPP
#define SHISHGL_UISELECTLIST_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "UIFrame.hpp"
#include "Clickable.hpp"

#include <iostream>
/*============================================================================*/
namespace Sh {

    class UISelectEvent : public Event {
    public:

        explicit UISelectEvent(int option)
            : opt(option)
            { }

        Mask mask() override {
            return Event::getMask<UISelectEvent>();
        }

        [[nodiscard]]
        int option() const {
            return opt;
        }

        bool happen(Listener* listener) override {
            return listener->onEvent(*this);
        }

    private:

        int opt;
    };

    class UIChooseEvent : public UISelectEvent {
    public:

        explicit UIChooseEvent(int option)
            : UISelectEvent(option)
            { }

        Mask mask() override {
            return Event::getMask<UIChooseEvent>();
        }

    };

    class Selectable : public Clickable {
    public:

        Selectable(UIWindow* target, int option)
                : Clickable(target)
                , opt(option)
                , selected(false)
                { }

        void reactOnRelease(MouseButtonEvent&) override {
            if (selected) {
                EventSystem::sendEvent<UIChooseEvent>(target<UIWindow>(), opt);
            } else {
                EventSystem::sendEvent<UISelectEvent>(target<UIWindow>(), opt);
                selected = true;
            }
        }

        bool onEvent(Event& event) override {

            if (event.mask() != Event::getMask<UISelectEvent>()) {
                return false;
            }

            auto select = dynamic_cast<UISelectEvent&>(event);

            if (select.option() == opt) {
                target<UIWindow>()->setState(UIWindow::SELECTED);
                selected = true;
            } else {
                target<UIWindow>()->setState(UIWindow::NORMAL);
                selected = false;
            }

            return true;
        }

    private:

        int opt;
        bool selected;
    };

    /*------------------------------------------------------------------------*/

    class UISelectList : public UIFrame {
    public:

        explicit UISelectList(const Frame& frame, double sb_width = 5)
                : UIFrame(frame, sb_width)
                { }

        virtual void update() {
            UIFrame::fit();
        }

        bool onEvent(Event& event) override {

            if (event.mask() == Event::getMask<UISelectEvent>()) {

                EventSystem::sendEvent(this, event);

                auto select = dynamic_cast<UISelectEvent&>(event);
                onSelect(select.option());

                return true;

            } else if (event.mask() == Event::getMask<UIChooseEvent>()) {

                auto choose = dynamic_cast<UIChooseEvent&>(event);
                onChoose(choose.option());

                return true;
            }

            return false;
        }

        virtual void onSelect(int) { }

        virtual void onChoose(int) { }
    };




}
/*============================================================================*/
#endif //SHISHGL_UISELECTLIST_HPP
/*============================================================================*/
