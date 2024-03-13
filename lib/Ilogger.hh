#pragma once

#include <string>
#include <fstream>

class ILogger
{
public:
    enum LogLevel
    {
        ERROR = 0,
        INFO = 1,
        DEBUG = 2,
    };

    ILogger() = default;
    virtual ~ILogger() = default;

    void setLevel(LogLevel level) { level_ = level; }
    virtual void info(const std::string &content) const = 0;
    virtual void error(const std::string &content) const = 0;
    virtual void debug(const std::string &content) const = 0;

protected:
    virtual void write(const std::string &content) const
    {
        outstream_->write(content.c_str(), content.size());
    }
    LogLevel level_ = DEBUG;
    std::ostream *outstream_;
};