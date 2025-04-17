#include "output_formatter.hpp"
#include <iostream>

void OutputFormatter::formatOutput(const std::string& format) {
    if (format == "json") {
        std::cout << "{ \"build_time\": 123, \"run_time\": 456 }\n";  // Example output, JSON structure.
    } else if (format == "csv") {
        std::cout << "build_time,run_time\n123,456\n";  // Example output, CSV format.
    } else {
        std::cout << "Build and run times printed in text format.\n";
    }
}
