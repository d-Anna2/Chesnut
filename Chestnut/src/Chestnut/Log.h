#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace chestnut {
    class CHESTNUT_API Log
    {
    public:
        static void init();
        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define CN_CORE_TRACE(...)   ::chestnut::Log::getCoreLogger()->trace(__VA_ARGS__)
#define CN_CORE_INFO(...)    ::chestnut::Log::getCoreLogger()->info(__VA_ARGS__)
#define CN_CORE_WARN(...)    ::chestnut::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CN_CORE_ERROR(...)   ::chestnut::Log::getCoreLogger()->error(__VA_ARGS__)
#define CN_CORE_FATAL(...)   ::chestnut::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CN_TRACE(...)        ::chestnut::Log::getClientLogger()->trace(__VA_ARGS__)
#define CN_INFO(...)         ::chestnut::Log::getClientLogger()->info(__VA_ARGS__)
#define CN_WARN(...)         ::chestnut::Log::getClientLogger()->warn(__VA_ARGS__)
#define CN_ERROR(...)        ::chestnut::Log::getClientLogger()->error(__VA_ARGS__)
#define CN_FATAL(...)        ::chestnut::Log::getClientLogger()->fatal(__VA_ARGS__)