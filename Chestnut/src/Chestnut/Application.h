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
    private:
        std::unique_ptr<Window> m_window;
        bool m_running;
        bool OnWindowClose(WindowCloseEvent& e);

        LayerStack m_layerStack;
    };

    // to be defined in client
    Application* createApplication();
}
