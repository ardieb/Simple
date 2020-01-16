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
        inline static std::shared_ptr<spdlog::async_logger>& getCoreLog() { return coreLog; }
        inline static std::shared_ptr<spdlog::async_logger>& getClientLog() { return clientLog; }
    private:
        static std::shared_ptr<spdlog::async_logger> clientLog;
        static std::shared_ptr<spdlog::async_logger> coreLog;
    };
}

// Core Log Macros
#define SIMPLE_CORE_TRACE(...)   ::Simple::Log::getCoreLog()->trace(__VA_ARGS__)
#define SIMPLE_CORE_INFO(...)    ::Simple::Log::getCoreLog()->info(__VA_ARGS__)
#define SIMPLE_CORE_WARN(...)    ::Simple::Log::getCoreLog()->warn(__VA_ARGS__)
#define SIMPLE_CORE_ERROR(...)   ::Simple::Log::getCoreLog()->error(__VA_ARGS__)
#define SIMPLE_CORE_FATAL(...)   ::Simple::Log::getCoreLog()->fatal(__VA_ARGS__)

//Client Log Macros
#define SIMPLE_CLIENT_TRACE(...)   ::Simple::Log::getClientLog()->trace(__VA_ARGS__)
#define SIMPLE_CLIENT_INFO(...)    ::Simple::Log::getClientLog()->info(__VA_ARGS__)
#define SIMPLE_CLIENT_WARN(...)    ::Simple::Log::getClientLog()->warn(__VA_ARGS__)
#define SIMPLE_CLIENT_ERROR(...)   ::Simple::Log::getClientLog()->error(__VA_ARGS__)
#define SIMPLE_CLIENT_FATAL(...)   ::Simple::Log::getClientLog()->fatal(__VA_ARGS__)

#endif //SIMPLE_LOG_H
