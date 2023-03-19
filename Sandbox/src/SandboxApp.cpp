#include <Chestnut.h>

class ExampleLayer: public chestnut::Layer {
public:
    ExampleLayer(): Layer("Example") {}
    void OnUpdate() override {
        if (chestnut::Input::isKeyPressed(CN_KEY_TAB)) {
            CN_INFO("Tab Key pressed");
        }
    }
    void OnEvent(chestnut::Event& event) override {
        if (event.GetEventType() == chestnut::EventType::KeyPressed) {
            chestnut::KeyPressedEvent &e = (chestnut::KeyPressedEvent&) event;
            CN_TRACE("{0}", (char) e.GetKeyCode());
        }
    }
};

class Sandbox: public chestnut::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
        PushOverlay(new chestnut::ImGuiLayer());
    }
};

chestnut::Application* chestnut::createApplication() {
    return new Sandbox();
}
