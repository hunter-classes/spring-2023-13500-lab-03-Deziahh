// add your code as appropriate
#include <iostream>

#include <fstream>
#include <cstdlib>
#include <climits>

#include <string>

#include "reservoir.h"

#include "reverseorder.h"

int main() {
    // Tests for each function
    std::string date4 = "01/01/2018";
    double east_storage = get_east_storage(date4);
    std::cout << "East basin storage on " << date4 << " was " << east_storage << " billion gallons." << std::endl;
    
    double lowest_storage = get_min_east();
    std::cout << "The minimum storage in the East Basin in 2018 is " << lowest_storage << std::endl;
    
    double max_storage = get_max_east();
    std::cout << "The maximum storage in the East Basin in 2018 is " << max_storage << std::endl;
    
    std::string date3 = "01/02/2018";
    std::string result = compare_basins(date3);
    std::cout << "On " << date3 << ", the " << result << " basin had a higher storage value." << "\n" << std::endl;
        
    std::string date1 = "01/03/2018";
    std::string date2 = "02/03/2018";
    reverse_order(date1, date2);
    //std::cout << "The West basin elevation for the interval is: " << result2 << std::endl;
    return 0;


    }
    
