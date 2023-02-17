#include "reverseorder.h"
#include "reservoir.h"
#include <iostream>
#include <vector>
#include <algorithm>

void reverse_order(std::string date1, std::string date2) {
    std::vector<std::string> dates;
    std::vector<double> west_storage;
    
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string date;
        double east_st, west_st;
        if (ss >> date >> east_st >> west_st) {
            if (date >= date1 && date <= date2) {
                dates.push_back(date);
                west_storage.push_back(west_st);
            }
        }
    }

    if (dates.empty()) {
        std::cout << "No data found in the specified date range." << std::endl;
        return;
    }

    std::cout << "West basin elevation for the period " << date1 << " - " << date2 << ":" << std::endl;

    std::reverse(dates.begin(), dates.end());
    std::reverse(west_storage.begin(), west_storage.end());

    for (size_t i = 0; i < dates.size(); i++) {
        std::cout << dates[i] << " " << west_storage[i] << " ft" << std::endl;
    }
}
