#pragma once
#include <stdexcept>
#include "INoise.hh"
#include "Ilogger.hh"

/// @brief Powerful algebra class
class AlgebraClass
{
public:
    AlgebraClass() = default;
    AlgebraClass(const INoise *noise) : noise_(noise) {}
    void setLogger(ILogger *logger) { logger_ = logger; }

    float squareTwo(float x) const { return x * x; }

    float squareTwoNoise(float x) const
    {
        if (!noise_)
            throw std::runtime_error("No noise object found!");

        return squareTwo(x) + noise_->addNoise();
    }

    float longOperation(float x) const
    {
        bool has_logger = logger_ ? true : false;

        if (has_logger)
            logger_->info("Long operationg starting...");

        float res = squareTwo(x);

        if (has_logger)
            logger_->info("Long operation over...");

        return res;
    }

private:
    // Dependencies
    const INoise *noise_ = nullptr;
    const ILogger *logger_ = nullptr;
};