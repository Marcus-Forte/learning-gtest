#pragma once
#include <stdexcept>

class Dependency
{
public:
    Dependency(float val) : val_(val) {}

    virtual float get() const { return val_; }

private:
    float val_;
};
class MainClass
{
public:
    MainClass() = default;
    MainClass(const Dependency *dep) : dep_(dep) {}

    float squareTwo(float x) { return x * x; }
    float squareTwo(const Dependency *dep)
    {
        float val = dep->get();
        return val * val;
    }

    float squareTwoDep() const
    {
        if(!dep_)
            throw std::runtime_error("Missing dependency!");

        float val = dep_->get();
        return val * val;
    }

private:
    const Dependency *dep_ = nullptr;
};