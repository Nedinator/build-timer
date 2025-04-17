#include "build_runner.hpp"
#include <cstdlib>

int BuildRunner::run(const std::string& command){
    return std::system(command.c_str());
}