#include "cnpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace chestnut {
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::init() {
        // %T ... timestamp, %n ... name of the logger, %v%$ ... message
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("CHESTNUT");
        s_CoreLogger->set_level(spdlog::level::trace);
        
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}
