#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace chestnut
{
    class CHESTNUT_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& e);
    private:
        std::unique_ptr<Window> m_window;
        bool m_running;
        bool OnWindowClose(WindowCloseEvent& e);
    };

    // to be defined in client
    Application* createApplication();
}
