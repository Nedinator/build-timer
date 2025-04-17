#include <CLI/CLI.hpp>
#include <iostream>
#include "timer.hpp"
#include "build_runner.hpp"
#include "output_formatter.hpp"

int main(int argc, char** argv) {
    CLI::App app{"Build Timer - Time your C++ builds and executions"};

    std::string build_cmd;
    std::string run_cmd;
    std::string output_format = "text";

    app.add_option("--build", build_cmd, "Build command (e.g., 'g++ main.cpp -o program')")->required();
    app.add_option("--run", run_cmd, "Run command (optional, e.g., './program')");
    app.add_option("--output", output_format, "Output format: text, json, csv")->default_val("text");

    // Parse the command-line arguments
    CLI11_PARSE(app, argc, argv);

    // Timing the build process
    Timer build_timer("Build Phase");
    int build_result = BuildRunner::run(build_cmd);
    build_timer.stop();

    if (build_result != 0) {
        std::cerr << "Build failed with exit code " << build_result << "\n";
        return build_result;
    }

    // If run command exists, time the execution process
    if (!run_cmd.empty()) {
        Timer run_timer("Run Phase");
        int run_result = BuildRunner::run(run_cmd);
        run_timer.stop();

        if (run_result != 0) {
            std::cerr << "Program execution failed with exit code " << run_result << "\n";
            return run_result;
        }
    }

    // Format the output (e.g., JSON, text, etc.)
    OutputFormatter::formatOutput(output_format);

    return 0;
}
