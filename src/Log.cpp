//
// Created by Arthur Burke on 2020-01-13.
//

#include <Simple/Log.h>

namespace Simple {
    std::shared_ptr<spdlog::logger> Log::core_logger;
    std::shared_ptr<spdlog::logger> Log::client_logger;

    void Log::create() {
        spdlog::set_pattern("%^[%T] %n %v%$");

        auto core_console_sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
        auto client_console_sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
        auto core_file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("DailyCoreLogger", "logs/core.txt", 2, 30);
        auto client_file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("DailyClientLogger", "logs/client.txt", 2, 30);

        core_console_sink->set_level(spdlog::level::trace);
        client_console_sink->set_level(spdlog::level::trace);
        core_file_sink->set_level(spdlog::level::debug);
        client_file_sink->set_level(spdlog::level::debug);

        auto core_log = spdlog::logger("CoreLogger", { core_console_sink, core_file_sink });
        auto client_log = spdlog::logger("ClientLogger", { client_console_sink, client_file_sink });

        core_logger = std::make_shared<spdlog::logger>(std::move(core_log));
        client_logger = std::make_shared<spdlog::logger>(std::move(client_log));
    }
};