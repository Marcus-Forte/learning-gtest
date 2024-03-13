#pragma once
#include "INoise.hh"
#include <gmock/gmock.h>

class MockNoise : public INoise {
    public:
    MockNoise() : INoise(0.0) {}
    MOCK_METHOD(float, addNoise, (), (const,override));
};