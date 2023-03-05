#include <Chestnut.h>

class ExampleLayer: public chestnut::Layer {
public:
    ExampleLayer(): Layer("Example") {}
    void OnUpdate() override {
        // CN_INFO("ExampleLayer OnUpdate");
    }
    void OnEvent(chestnut::Event& event) override {
        CN_TRACE("{0}", event);
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
