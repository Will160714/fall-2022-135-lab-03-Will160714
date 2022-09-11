#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reservoir.h"

double get_east_storage(std::string date){
    std::cout << "Enter date: " << date << std::endl;

    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    std::string junk;        // new string variable
    getline(fin, junk); // read one line from the file

    std::string data_date;
    double eastSt;
    
    while(fin >> data_date >> eastSt) { 
        if((date == data_date) == 1){
            std::cout << "East basin storage: " << eastSt << " billion gallons" << std::endl;
        }
      
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 
    }

    fin.close();

    return 0.0;
}

double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    std::string junk;        // new string variable
    getline(fin, junk); // read one line from the file

    std::string data_date;
    double eastSt;
    double min;
    bool first_value = true;

    while(fin >> data_date >> eastSt) { 
        if(first_value){
            min = eastSt;
            first_value = false;
        }

        if(min >= eastSt){
            min = eastSt;
        }
      
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 
    }

    fin.close();

    return min;
}

double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    std::string junk;        // new string variable
    getline(fin, junk); // read one line from the file

    std::string data_date;
    double eastSt;
    double max;
    bool first_value = true;

    while(fin >> data_date >> eastSt) { 
        if(first_value){
            max = eastSt;
            first_value = false;
        }

        if(max <= eastSt){
            max = eastSt;
        }
      
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 
    }

    fin.close();

    return max;
}

std::string compare_basins(std::string date){

    std::ifstream fin("Current_Reservoir_Levels.tsv");
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
    
    while(fin >> data_date >> eastSt >> eastE1 >> westSt >> westE1) { 
        if((date == data_date) == 1){
            if(eastE1 > westE1)
                return "East";
            else if(eastE1 < westE1)
                return "West";
            else
                return "Equal";
        }
      
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 
    }

    fin.close();

    return "";

}