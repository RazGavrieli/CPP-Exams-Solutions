#pragma once
#include <iostream>

class RunningAverage {
    float sum;
    size_t size; 
    public:
        RunningAverage() : sum(0), size(0) {}
        RunningAverage(const RunningAverage& other) : sum(other.sum), size(other.size) {}

        friend std::ostream& operator<<(std::ostream& out, const RunningAverage& self);
        RunningAverage& operator+=(double x);
        const RunningAverage& operator+(double x) const;
        RunningAverage& operator=(const RunningAverage& other);
};