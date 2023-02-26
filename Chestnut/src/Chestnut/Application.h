#pragma once

#include "Core.h"
#include "Window.h"
#include "Chestnut/LayerStack.h"
#include "Chestnut/Events/ApplicationEvent.h"

namespace chestnut
{
    class CHESTNUT_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        inline static Application& Get() {
            return *s_instance;
        }

        inline Window& GetWindow() { return *m_window; }
    private:
        std::unique_ptr<Window> m_window;
        bool m_running;
        bool OnWindowClose(WindowCloseEvent& e);

        LayerStack m_layerStack;

        static Application* s_instance;
    };

    // to be defined in client
    Application* createApplication();
}
