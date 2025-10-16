#include "Log.h"
#include <memory>
#include <string>
#include <iostream>
#include <filesystem>
#include <cstdarg>
#include <vector>

#define SPDLOG_WCHAR_TO_UTF8_SUPPORT
#define SPDLOG_COMPILED_LIB
#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

// 转换LogLevel到spdlog level
spdlog::level::level_enum to_spdlog_level(LogLevel level) {
    switch (level) {
    case LogLevel::TRACE:    return spdlog::level::trace;
    case LogLevel::DEBUG:    return spdlog::level::debug;
    case LogLevel::INFO:     return spdlog::level::info;
    case LogLevel::WARN:     return spdlog::level::warn;
    case LogLevel::ERROR:    return spdlog::level::err;
    case LogLevel::CRITICAL: return spdlog::level::critical;
    case LogLevel::OFF:      return spdlog::level::off;
    default:                 return spdlog::level::info;
    }
}

class LoggerImpl {
public:
    LoggerImpl() : initialized(false) {}

    bool initialize(const std::string& log_dir, const std::string& log_name, LogLevel level) {
        try {
            std::filesystem::create_directories(log_dir);

            // 创建每日文件sink
            auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(
                log_dir + "/" + log_name + ".log", 2, 30);

            // 创建控制台sink
            auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

            // 创建多sink logger
            std::vector<spdlog::sink_ptr> sinks {daily_sink, console_sink};
            logger = std::make_shared<spdlog::logger>("multi_sink", sinks.begin(), sinks.end());

            // 设置日志配置
            logger->set_level(to_spdlog_level(level));
            logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] [%P] [%t] %v");
            logger->flush_on(to_spdlog_level(level));

            spdlog::register_logger(logger);
            spdlog::set_default_logger(logger);

            initialized = true;
            return true;
        } catch (const std::exception& ex) {
            std::cerr << "Logger initialization failed: " << ex.what() << std::endl;
            return false;
        }
    }

    void log(spdlog::level::level_enum level, const char* fmt, va_list args) {
        if (!initialized) return;

        char buffer[4096];
        vsnprintf(buffer, sizeof(buffer), fmt, args);
        logger->log(level, buffer);
    }

    void set_level(LogLevel level) {
        if (initialized) {
            logger->set_level(to_spdlog_level(level));
        }
    }

    void flush() {
        if (initialized) {
            logger->flush();
        }
    }

    void shutdown() {
        if (initialized) {
            flush();
            spdlog::drop_all();
            initialized = false;
        }
    }

    bool is_initialized() const { return initialized; }

private:
    std::shared_ptr<spdlog::logger> logger;
    bool initialized;
};

// 全局实例
static LoggerImpl g_logger;

// C接口实现
LOG_EXPORT bool Logger_Initialize(const char* log_dir, const char* log_name, LogLevel level) {
    return g_logger.initialize(log_dir ? log_dir : "./logs",
                               log_name ? log_name : "app",
                               level);
}

LOG_EXPORT void Logger_Trace(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::trace, fmt, args);
    va_end(args);
}

LOG_EXPORT void Logger_Debug(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::debug, fmt, args);
    va_end(args);
}

LOG_EXPORT void Logger_Info(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::info, fmt, args);
    va_end(args);
}

LOG_EXPORT void Logger_Warn(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::warn, fmt, args);
    va_end(args);
}

LOG_EXPORT void Logger_Error(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::err, fmt, args);
    va_end(args);
}

LOG_EXPORT void Logger_Critical(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::critical, fmt, args);
    va_end(args);
}

LOG_EXPORT void Logger_SetLevel(LogLevel level) {
    g_logger.set_level(level);
}

LOG_EXPORT void Logger_Flush() {
    g_logger.flush();
}

LOG_EXPORT void Logger_Shutdown() {
    g_logger.shutdown();
}

// C++ 类实现
Log& Log::GetInstance() {
    static Log instance;
    return instance;
}

Log::Log() {}
Log::~Log() { Shutdown(); }

bool Log::Initialize(const std::string& log_dir, const std::string& log_name, LogLevel level) {
    return Logger_Initialize(log_dir.c_str(), log_name.c_str(), level);
}

void Log::Trace(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::trace, fmt, args);
    va_end(args);
}

void Log::Debug(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::debug, fmt, args);
    va_end(args);
}

void Log::Info(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::info, fmt, args);
    va_end(args);
}

void Log::Warn(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::warn, fmt, args);
    va_end(args);
}

void Log::Error(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::err, fmt, args);
    va_end(args);
}

void Log::Critical(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    g_logger.log(spdlog::level::critical, fmt, args);
    va_end(args);
}

void Log::SetLevel(LogLevel level) {
    g_logger.set_level(level);
}

void Log::Flush() {
    g_logger.flush();
}

void Log::Shutdown() {
    g_logger.shutdown();
}

// int main() {
//     // 方式1: 使用C接口
//     Logger_Initialize("./logs", "myapp", LogLevel::DEBUG);

//     Logger_Info("应用程序启动 - C接口");
//     Logger_Debug("调试信息: %s, 数值: %d", "测试", 42);
//     Logger_Error("错误信息: 文件 %s 不存在", "config.ini");

//     // 方式2: 使用C++类接口
//     Logger::GetInstance().Initialize("./logs", "myapp_cpp", LogLevel::DEBUG);
//     Logger::GetInstance().Info("C++接口日志记录");
//     Logger::GetInstance().Debug("格式化消息: %s %f", "测试", 3.14);

//     Logger_Shutdown();
//     return 0;
// }
