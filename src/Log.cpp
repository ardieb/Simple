//
// Created by Arthur Burke on 2020-01-13.
//

#include <Simple/Utility/Log.h>

namespace Simple {
    std::shared_ptr<spdlog::async_logger> Log::coreLog;
    std::shared_ptr<spdlog::async_logger> Log::clientLog;

    void Log::create() {
        spdlog::set_pattern("%^[%T] %n %v%$");
        {
            std::vector<spdlog::sink_ptr> sinks;
            sinks.push_back(
                    std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>());
            sinks.push_back(
                    std::make_shared<spdlog::sinks::daily_file_sink<std::mutex, spdlog::sinks::dateonly_daily_file_name_calculator>>(
                            "log/core_log.txt", 0, 0));
            coreLog = std::make_shared<spdlog::async_logger>(
                    "Log", begin(sinks), end(sinks), 32768);
        }
        {
            std::vector<spdlog::sink_ptr> sinks;
            sinks.push_back(
                    std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>());
            sinks.push_back(
                    std::make_shared<spdlog::sinks::daily_file_sink<std::mutex, spdlog::sinks::dateonly_daily_file_name_calculator>>(
                            "log/client_log.txt", 0, 0));
            clientLog = std::make_shared<spdlog::async_logger>(
                    "Log", begin(sinks), end(sinks), 32768);
        }

    }
};