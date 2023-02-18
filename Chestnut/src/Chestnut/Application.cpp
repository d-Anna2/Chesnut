#include "cnpch.h"
#include "Application.h"

#include "Chestnut/Log.h"
#include "Chestnut/Events/ApplicationEvent.h"

namespace chestnut {
    Application::Application() {
    }

    Application::~Application() {    
    }

    void Application::Run() {
        WindowResizeEvent e(1200, 123);
        CN_TRACE(e);
        while (true);
    }


}
