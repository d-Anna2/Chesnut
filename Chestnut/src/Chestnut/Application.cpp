#include "cnpch.h"
#include "Application.h"

#include "Chestnut/Log.h"
#include <GLFW/glfw3.h>

namespace chestnut {
    #define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
    
    Application::Application() {
        m_running = true;
        m_window = std::unique_ptr<Window>(Window::Create());
        m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
    }

    void Application::Run() {
        
        while (true) {
            glClearColor(0, 1, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_window->OnUpdate();
            if (!m_running) exit(0); // workaround
        }
    }

    void Application::OnEvent(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        CN_CORE_TRACE("{0}", e);
    }

    bool Application::OnWindowClose(WindowCloseEvent& e) {
        m_running = false;
        return true;
    }


}
