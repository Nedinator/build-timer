#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>
#include <string>

class Timer {
    public:
        explicit Timer(const std::string& label);
        void stop();

    private:
        std::string label_;
        std::chrono::steady_clock::time_point start_;      
};

#endif 