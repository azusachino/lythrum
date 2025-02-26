#ifndef BENCHMARK_UTILS_H
#define BENCHMARK_UTILS_H

#include <chrono>
#include <iostream>
#include <string>

class BenchmarkUtils {
public:
    static void startTimer(std::chrono::steady_clock::time_point& start) {
        start = std::chrono::steady_clock::now();
    }

    static double stopTimer(const std::chrono::steady_clock::time_point& start) {
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        return elapsed.count();
    }

    static void logResults(const std::string& testName, double duration) {
        std::cout << "Test: " << testName << " | Duration: " << duration << " seconds" << std::endl;
    }
};

#endif // BENCHMARK_UTILS_H