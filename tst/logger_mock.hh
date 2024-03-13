#pragma once

#include "Ilogger.hh"
#include <gmock/gmock.h>
class MockLogger : public ILogger
{
public:
    MOCK_METHOD(void, info, (const std::string &), (const, override));
    MOCK_METHOD(void, error, (const std::string &), (const, override));
    MOCK_METHOD(void, debug, (const std::string &), (const, override));

    // virtual void info(const std::string &content) const = 0;
    // virtual void error(const std::string &content) const = 0;
    // virtual void debug(const std::string &content) const = 0;
};