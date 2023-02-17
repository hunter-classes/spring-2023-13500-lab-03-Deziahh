// add your code as appropriate
#include <iostream>

#include <fstream>
#include <cstdlib>
#include <climits>

#include <string>

#include "reservoir.h"

int main() {
    // Tests for each function
    std::string date = "01/01/2018";
    double east_storage = get_east_storage(date);
    std::cout << "East basin storage on " << date << " was " << east_storage << " billion gallons." << std::endl;
    
    double lowest_storage = get_min_east();
    std::cout << "The minimum storage in the East Basin in 2018 is " << lowest_storage << std::endl;
    
    double max_storage = get_max_east();
    std::cout << "The maximum storage in the East Basin in 2018 is " << max_storage << std::endl;
    
    std::string dates = "01/02/2018";
    std::string result = compare_basins(date);
    std::cout << "On " << date << ", the " << result << " basin had a higher storage value." << std::endl;
        
    return 0;


    }
    
