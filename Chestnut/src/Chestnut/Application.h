#pragma once

#include "Core.h"
#include "Chestnut/Events/Event.h"

namespace chestnut
{
    class CHESTNUT_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // to be defined in client
    Application* createApplication();
}