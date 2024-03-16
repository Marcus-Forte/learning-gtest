#pragma once

#include <fstream>
#include <iostream>
#include "Ilogger.hh"

class FileLogger : public ILogger
{
public:
    enum SINK
    {
        FILE,
        COUT
    };
    FileLogger(const std::string &filename = "file.log", SINK sink = FILE) : sink_(sink)
    {
        if (sink == FILE)
            outstream_ = new std::ofstream(filename);
        else
            outstream_ = &std::cout;
    }

    virtual ~FileLogger()
    {
        if(sink_ == FILE)
            delete outstream_;
    }

    virtual void info(const std::string &content) const
    {
        if (level_ < LogLevel::INFO)
            return;
        *outstream_ << "Info::";
        write(content);
    }
    virtual void error(const std::string &content) const
    {

        *outstream_ << "Error::";
        write(content);
    }
    virtual void debug(const std::string &content) const
    {
        if (level_ < LogLevel::DEBUG)
            return;
        *outstream_ << "Debug::";
        write(content);
    }

private:
    SINK sink_;
};