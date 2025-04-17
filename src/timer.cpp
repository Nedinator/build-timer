#include "timer.hpp"

Timer::Timer(const std::string& label) : label_(label), start_(std::chrono::steady_clock::now()) {}

void Timer::stop() {
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start_);
    std::cout << "[Timer] " << label_ << ": " << duration.count() << " ms\n";
}