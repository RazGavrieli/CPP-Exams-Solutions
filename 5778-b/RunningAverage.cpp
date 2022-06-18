/*
class RunningAverage {
    float sum;
    size_t size; 
    public:
        RunningAverage() : sum(0), size(0) {}
        RunningAverage(const RunningAverage& other) : sum(other.sum), size(other.size) {}

        friend std::ostream& operator<<(std::ostream& out, const RunningAverage& self);
        RunningAverage& operator+=(double x);
        RunningAverage& operator+(double x);
        RunningAverage& operator=(const RunningAverage& other);
};
*/
#include "RunningAverage.h"

std::ostream& operator<<(std::ostream& out, const RunningAverage& self) {
    out << self.sum/self.size; // << Using private members of RunningAverage, so at function declaration we used 'friend' 
    return out;
}

RunningAverage& RunningAverage::operator+=(double x) {
    this->sum += x;
    this->size++;
    return *this;
}

const RunningAverage& RunningAverage::operator+(double x) const {
    RunningAverage newavg(*this);
    newavg += x;
    return newavg;
}

RunningAverage& RunningAverage::operator=(const RunningAverage& other) {
    // No need to delete anything from the heap (we didn't allocate anything)
    this->size = other.size;
    this->sum = other.sum;
    return *this;
}