//
// Created by Arthur Burke on 2020-01-13.
//

#ifndef SIMPLE_LOG_H
#define SIMPLE_LOG_H

#include <Simple/SimpleCore.h>
#include <spdlog/spdlog.h>

namespace Simple {
    class Log {
    public:
        static void create();
        inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return core_logger; }
        inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return client_logger; }
    private:
        static std::shared_ptr<spdlog::logger> client_logger;
        static std::shared_ptr<spdlog::logger> core_logger;
    };
}

// Core Log Macros
#define SIMPLE_CORE_TRACE(...)   ::Simple::Log::get_core_logger()->trace(__VA_ARGS__)
#define SIMPLE_CORE_INFO(...)    ::Simple::Log::get_core_logger()->info(__VA_ARGS__)
#define SIMPLE_CORE_WARN(...)    ::Simple::Log::get_core_logger()->warn(__VA_ARGS__)
#define SIMPLE_CORE_ERROR(...)   ::Simple::Log::get_core_logger()->error(__VA_ARGS__)
#define SIMPLE_CORE_FATAL(...)   ::Simple::Log::get_core_logger()->fatal(__VA_ARGS__)

//Client Log Macros
#define SIMPLE_CLIENT_TRACE(...)   ::Simple::Log::get_client_logger()->trace(__VA_ARGS__)
#define SIMPLE_CLIENT_INFO(...)    ::Simple::Log::get_client_logger()->info(__VA_ARGS__)
#define SIMPLE_CLIENT_WARN(...)    ::Simple::Log::get_client_logger()->warn(__VA_ARGS__)
#define SIMPLE_CLIENT_ERROR(...)   ::Simple::Log::get_client_logger()->error(__VA_ARGS__)
#define SIMPLE_CLIENT_FATAL(...)   ::Simple::Log::get_client_logger()->fatal(__VA_ARGS__)

#endif //SIMPLE_LOG_H
