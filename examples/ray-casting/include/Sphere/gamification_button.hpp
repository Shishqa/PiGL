/*============================================================================*/
#ifndef INC_02_SPHERE_RENDERING_GAMIFICATION_BUTTON_HPP
#define INC_02_SPHERE_RENDERING_GAMIFICATION_BUTTON_HPP
/*============================================================================*/

#include "ShishGL/button.hpp"

using namespace ShishGL;

/*============================================================================*/

class GameButton : public Button {
public:

    GameButton();

    ~GameButton() override = default;

private:

    void onRender() override;

    void onMouseClick(int button, int state, int x, int y) override;

};

/*============================================================================*/
#endif //INC_02_SPHERE_RENDERING_GAMIFICATION_BUTTON_HPP
/*============================================================================*/
