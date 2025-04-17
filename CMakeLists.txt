cmake_minimum_required(VERSION 3.5)
project(build-timer)

# Specify C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch and link CLI11
include(FetchContent)
FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
)

FetchContent_MakeAvailable(CLI11)

# Add executable
add_executable(build-timer
    src/main.cpp
    src/timer.cpp
    src/build_runner.cpp
    src/output_formatter.cpp
)

# Link CLI11
target_link_libraries(build-timer PRIVATE CLI11::CLI11)
