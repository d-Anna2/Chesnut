#include "cnpch.h"
#include "WindowsInput.h"

#include "WindowsWindow.h"
#include "Chestnut/Application.h"

namespace chestnut {

    Input* Input::s_instance = new WindowsInput();
    
    bool WindowsInput::isKeyPressedImpl(int keycode) {
        auto window  = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::isMouseButtonPressedImpl(int button) {
        auto window  = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInput::getMousePositionImpl() {
        auto window  = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);
        return { static_cast<float>(xPos), static_cast<float>(yPos) };
    }


    float WindowsInput::getMouseXImpl() {
        auto [x, y] = getMousePositionImpl();
        return x;
    }

    float WindowsInput::getMouseYImpl() {
        auto [x, y] = getMousePositionImpl();
        return y;
    }



    
}
