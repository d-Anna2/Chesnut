#pragma once
#include "Chestnut/Layer.h"
#include "Chestnut/Events/ApplicationEvent.h"
#include "Chestnut/Events/KeyEvent.h"
#include "Chestnut/Events/MouseEvent.h"

namespace chestnut {
    class CHESTNUT_API ImGuiLayer: public Layer{
public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnUpdate() override;
        void OnEvent(Event& event) override;
        void OnAttach() override;
        void OnDetach() override;
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowsResizedEvent(WindowResizeEvent& e);

        float m_time = 0.0f;
};
}
