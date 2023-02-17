#pragma once

#ifdef CN_PLATFORM_WINDOWS
    #ifdef CN_BUILD_DLL
        #define CHESTNUT_API __declspec(dllexport)
    #else
        #define CHESTNUT_API __declspec(dllimport)
    #endif
#else
    #error Cestnut only supports Windows!
#endif
