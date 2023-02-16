// add your code as appropriate


#include <iostream>

#include <fstream>
#include <cstdlib>
#include <climits>

#include <string>

int main() {
    std::string date;
    double eastSt, eastEl, westSt, westEl;
    // Create an input file stream object and open the file
    std::ifstream input_file("Current_Reservoir_Levels.tsv");
    
    // Check if the file was opened successfully
    if (!input_file) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    
    // Read the contents of the file
    std::string line;
    std::getline(input_file, line);
    while(input_file >> date >> eastSt >> eastEl >> westSt >> westEl) {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration
        
        input_file.ignore(INT_MAX, '\n'); //skips to the end of line,
                              //ignorring the remaining columns

        // for example, to print the date and East basin storage:
        std::cout << date << " " << eastSt << std::endl;
    }
    return 0;
}
