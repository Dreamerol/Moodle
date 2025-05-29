// Moodle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "System.h"
int main()
{


    System system;
    Administrator admin;
    //system.run(std::cin);
    //// Simulate some commands:
    std::ifstream file("lol.txt");
    std::ofstream fil1("lol1.txt");
    if (!file) {
        return 0;
    }
    system.run(file, std::cout);
    system.readFromFile("lol2.txt");
    system.writeInFile("lol1.txt");
//    file.close();


}

