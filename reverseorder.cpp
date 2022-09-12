#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reserveorder.h"
#include <string>

void reverse_oreder(std::string date1, std::string date2){
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    std::string junk;        // new string variable
    getline(fin, junk); // read one line from the file

    std::string data_date;
    double eastSt;
    double eastE1;
    double westSt;
    double westE1;

    const int SIZE = 366;
    double west_Elevation[SIZE];
    string dates[SIZE];
    int current_size = 0;
    bool start = false;

    while(fin >> data_date >> eastSt >> eastE1 >> westSt >> westE1) { 
        if((date1 == data_date) == 1){
            start = true;
        }

        if(start){
            west_Elevation[current_size] = westE1;
            dates[current_size] = data_date;
            current_size ++;
        }

        if((date1 == data_date) == 1){
            start = false;
            break;
        }
      
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 
    }

    fin.close();

    for(int x = current_size; x >= 0; x--){
        std::cout << dates[current_size] << " " << west_Elevation[current_size] << std::endl;
    }

}