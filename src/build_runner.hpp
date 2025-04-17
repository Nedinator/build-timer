#ifndef BUILD_RUNNER_HPP
#define BUILD_RUNNER_HPP

#include <string>

class BuildRunner {
    public:
        static int run(const std::string& command);
};

#endif 