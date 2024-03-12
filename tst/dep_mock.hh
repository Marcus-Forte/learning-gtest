#pragma once

#include "class.hh"
#include <gmock/gmock.h> // Brings in gMock.

class DepMock
{
public:
    DepMock() : Dependency(1.0) {}
    MOCK_METHOD(float, get, (), (const,));
};