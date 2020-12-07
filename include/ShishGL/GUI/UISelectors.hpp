/*============================================================================*/
#ifndef SHISHGL_UISELECTORS_HPP
#define SHISHGL_UISELECTORS_HPP
/*============================================================================*/
#include "Vector2.hpp"
/*============================================================================*/
namespace Sh {

    class ICallback {
    public:

        virtual void operator()() = 0;

        virtual ~ICallback() = default;
    };

    /*------------------------------------------------------------------------*/

    class ITumbler : public ICallback {
    public:

        explicit ITumbler(bool turned_on = false)
            : on(turned_on)
            { }

        void operator()() override {
            on = !on;
        }

        ~ITumbler() override = default;

    private:

        bool on;
    };

    /*------------------------------------------------------------------------*/

    template <typename T>
    class IValueSetter {
    public:

        virtual void operator()(const T& value) = 0;

        virtual ~IRangeSetter() = default;
    };

    template <typename T>
    class IVectorSetter {
    public:

        virtual void operator()(const Vector2<T>& vec) = 0;

        virtual ~IVectorSetter() = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_UISELECTORS_HPP
/*============================================================================*/