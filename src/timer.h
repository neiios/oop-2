#ifndef OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_TIMER_H
#define OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_TIMER_H

#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
};

#endif //OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_TIMER_H
