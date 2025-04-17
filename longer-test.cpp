#include <iostream>
#include <chrono>
#include <thread>
#include <random>

int main() {
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 1000);  // Random delay between 100ms and 1000ms

    // Random delay
    int delay = dis(gen);  // Random delay value between 100 and 1000 milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));  // Simulate work by sleeping

    // Just some dummy work to ensure the compiler doesn't optimize away the delay
    long long sum = 0;
    for (int i = 0; i < 1000; ++i) {
        sum += i; 
    }

    return 0;
}
