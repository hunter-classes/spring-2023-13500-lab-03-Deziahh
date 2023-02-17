// add your code
#include <iostream>

#include <fstream>
#include <sstream>
#include "reservoir.h"

double get_east_storage(std::string date) {
    // Open the data file for reading
    std::ifstream input_file("Current_Reservoir_Levels.tsv");
    if (!input_file) {
        std::cerr << "Error opening file." << std::endl;
        return 0;
    }

    // Read the data from the file
    std::string line;
    while (std::getline(input_file, line)) {
        std::stringstream ss(line);
        std::string date_string;
        double east_storage;
        if (ss >> date_string >> east_storage) {
            if (date_string == date) {
                return east_storage;
            }
        }
    }

    // If we reach this point, the date was not found in the file
    std::cerr << "Date not found in file." << std::endl;
    return 0;
}
