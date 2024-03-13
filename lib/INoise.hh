#pragma once


class INoise {
    public:
    INoise(float mean) : mean_(mean) {}
    
    virtual float addNoise() const = 0;
    
    private: 
    float mean_;
};