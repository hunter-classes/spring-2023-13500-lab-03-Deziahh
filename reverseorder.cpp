#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2) {
    // Open the data file for reading
    std::ifstream input_file("Current_Reservoir_Levels.tsv");
    if (!input_file) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    // Read the data from the file and store it in a vector of strings
    std::vector<std::string> data_lines;
    std::string line;
    while (std::getline(input_file, line)) {
        data_lines.push_back(line);
    }

    // Find the indices of the lines corresponding to date1 and date2
    int date1_index = -1;
    int date2_index = -1;
    for (int i = 0; i < data_lines.size(); i++) {
        std::string current_date = data_lines[i].substr(0, 10);
        if (current_date == date1) {
            date1_index = i;
        }
        if (current_date == date2) {
            date2_index = i;
            break;
        }
    }

    // If date2 comes before date1 in the data file, swap the indices
    if (date1_index > date2_index) {
        int temp = date1_index;
        date1_index = date2_index;
        date2_index = temp;
    }

    // Print out the West basin elevation for all days in the interval in reverse chronological order
    for (int i = date2_index; i >= date1_index; i--) {
        std::string line = data_lines[i];
        std::string date = line.substr(0, 10);
        double west_storage = std::stod(line.substr(20, 7));
        std::cout << date << " " << west_storage << std::endl;
    }
}
