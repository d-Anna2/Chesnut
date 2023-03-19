#include "cnpch.h"
#include "Application.h"

#include "Chestnut/Log.h"
#include <GLFW/glfw3.h>

#include "Input.h"
#include "glad/glad.h"

namespace chestnut {
    #define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    Application* Application::s_instance = nullptr;
    
    Application::Application() {
        CN_CORE_ASSERT(!s_instance, "Application already exists");
        s_instance = this;
        m_window = std::unique_ptr<Window>(Window::Create());
        m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application() { }

    void Application::PushLayer(Layer* layer) {
        m_layerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* overlay) {
        m_layerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }
    
    void Application::Run() {
        while (m_Running) {
            glClearColor(0, 1, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            for (Layer* layer: m_layerStack) layer->OnUpdate();
         //   auto [x, y] = Input::getMousePosition();
         //   CN_TRACE("---{0}, {1}---", x, y);
            
            m_window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        // CN_CORE_TRACE("{0}", e);
        for (auto it = m_layerStack.end(); it != m_layerStack.begin();(*--it)->OnEvent(e)) {
            if (e.m_handled)
                break;
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e) {
        m_Running = false;
        return true;
    }


}
