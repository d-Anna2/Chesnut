#pragma once
#include "Application.h"

#ifdef CN_PLATFORM_WINDOWS

extern chestnut::Application* chestnut::createApplication();

int main(int argc, char* argv[])
{
    auto app = chestnut::createApplication();
    app->Run();
    delete app;
    return 0;
}

#endif