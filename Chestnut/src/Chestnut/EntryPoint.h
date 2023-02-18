#pragma once
#include "Application.h"
#include "Log.h"  

#ifdef CN_PLATFORM_WINDOWS

extern chestnut::Application* chestnut::createApplication();

int main(int argc, char* argv[]) {
    chestnut::Log::init();
    CN_CORE_WARN("Initialized log!");
    int a = 42;
    CN_INFO("Hello Variable = {0}", a);
    
    auto app = chestnut::createApplication();
    app->Run();
    delete app;
    return 0;
}

#endif
