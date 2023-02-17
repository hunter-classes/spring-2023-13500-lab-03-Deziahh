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

double get_min_east() {
    // Open the data file for reading
    std::ifstream input_file("Current_Reservoir_Levels.tsv");
    if (!input_file) {
        std::cerr << "Error opening file." << std::endl;
        return 0;
    }

    // Read the data from the file
    double min_east_storage = std::numeric_limits<double>::infinity();
    std::string line;
    while (std::getline(input_file, line)) {
        std::stringstream ss(line);
        std::string date_string;
        double east_storage;
        if (ss >> date_string >> east_storage) {
            if (east_storage < min_east_storage) {
                min_east_storage = east_storage;
            }
        }
    }

    // If we reach this point, we have read all the data in the file
    input_file.close();

    return min_east_storage;
}

double get_max_east() {
    // Open the data file for reading
    std::ifstream input_file("Current_Reservoir_Levels.tsv");
    if (!input_file) {
        std::cerr << "Error opening file." << std::endl;
        return 0;
    }

    // Read the data from the file
    double max_east_storage = -1.0;
    std::string line;
    while (std::getline(input_file, line)) {
        std::stringstream ss(line);
        std::string date_string;
        double east_storage;
        if (ss >> date_string >> east_storage) {
            if (east_storage > max_east_storage) {
                max_east_storage = east_storage;
            }
        }
    }

    // If we reach this point, we have read all the data in the file
    input_file.close();

    return max_east_storage;
}

std::string compare_basins(std::string date) {
    // Open the data file for reading
    std::ifstream input_file("Current_Reservoir_Levels.tsv");
    if (!input_file) {
        std::cerr << "Error opening file." << std::endl;
        return "Error";
    }

    // Read the data from the file
    double east_storage = -1.0;
    double west_storage = -1.0;
    std::string line;
    while (std::getline(input_file, line)) {
        std::stringstream ss(line);
        std::string date_string;
        double east_storage_tmp, west_storage_tmp;
        if (ss >> date_string >> east_storage_tmp >> west_storage_tmp) {
            if (date_string == date) {
                east_storage = east_storage_tmp;
                west_storage = west_storage_tmp;
                break;
            }
        }
    }

    // If we reach this point, either we found the data for the specified date or we reached the end of the file
    if (east_storage == -1.0 || west_storage == -1.0) {
        // Data for the specified date was not found
        return "Error: Data for specified date not found.";
    } else if (east_storage > west_storage) {
        return "East";
    } else if (west_storage > east_storage) {
        return "West";
    } else {
        return "Equal";
    }
}

