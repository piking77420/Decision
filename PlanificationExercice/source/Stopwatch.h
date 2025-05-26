#pragma once
#include <chrono>

class Stopwatch
{
public:
    void Start()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    float GetTimeElapsed() const
    {
        auto duration = std::chrono::high_resolution_clock::now() - start;
        return std::chrono::duration<float, std::micro>(duration).count();
    }
    
private:

    std::chrono::high_resolution_clock::time_point start;
    
};
