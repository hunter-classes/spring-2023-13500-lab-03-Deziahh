// add your code as appropriate
#include <iostream>

#include <fstream>
#include <cstdlib>
#include <climits>

#include <string>

#include "reservoir.h"

int main() {
    // Test the get_east_storage function with a date string
    std::string date = "01/01/2018";
    double east_storage = get_east_storage(date);
    std::cout << "East basin storage on " << date << " was " << east_storage << " billion gallons." << std::endl;
    
    double lowest_storage = get_min_east();
    std::cout << "The minimum storage in the East Basin in 2018 is "<< lowest_storage << std::endl;

        return 0;
    }
    
