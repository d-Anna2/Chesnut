#pragma once
#include "Chestnut/Input.h"

namespace chestnut {
    class WindowsInput: public Input {
    public:
    protected:
        bool isKeyPressedImpl(int keycode) override; 
        bool isMouseButtonPressedImpl(int button) override;
        std::pair<float, float> getMousePositionImpl() override;
        float getMouseXImpl() override;
        float getMouseYImpl() override;
    };
}
