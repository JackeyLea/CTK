#ifndef LOG_H
#define LOG_H

#include <string>

#include "log_global.h"

// 日志级别枚举
enum class LogLevel {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL,
    OFF
};

// C类型接口
extern "C" {
// 初始化日志系统
LOG_EXPORT bool Logger_Initialize(const char* log_dir = "./logs",
                                  const char* log_name = "app",
                                  LogLevel level = LogLevel::INFO);

// 记录日志
LOG_EXPORT void Logger_Trace(const char* fmt, ...);
LOG_EXPORT void Logger_Debug(const char* fmt, ...);
LOG_EXPORT void Logger_Info(const char* fmt, ...);
LOG_EXPORT void Logger_Warn(const char* fmt, ...);
LOG_EXPORT void Logger_Error(const char* fmt, ...);
LOG_EXPORT void Logger_Critical(const char* fmt, ...);

// 工具函数
LOG_EXPORT void Logger_SetLevel(LogLevel level);
LOG_EXPORT void Logger_Flush();
LOG_EXPORT void Logger_Shutdown();
}

// C++ 封装类
class LOG_EXPORT Log {
public:
    static Log& GetInstance();

    bool Initialize(const std::string& log_dir = "./logs",
                    const std::string& log_name = "app",
                    LogLevel level = LogLevel::INFO);

    void Trace(const char* fmt, ...);
    void Debug(const char* fmt, ...);
    void Info(const char* fmt, ...);
    void Warn(const char* fmt, ...);
    void Error(const char* fmt, ...);
    void Critical(const char* fmt, ...);

    void SetLevel(LogLevel level);
    void Flush();
    void Shutdown();

private:
    Log();
    ~Log();
    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;
};

#endif // LOG_H
