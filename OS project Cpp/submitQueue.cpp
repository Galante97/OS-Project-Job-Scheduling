//
//  submitQueue.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/8/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#include "submitQueue.hpp"

#include <iostream>
#include <fstream>
#include "systemConfigurations.h"
using namespace std;


void SubmitQueue::readFile() {
    std::ifstream file("sampleInput.txt");
    std::string str;
    
    
  while (std::getline(file, str)) {
        // Process str
        std::cout << str;
        std::cout << "\n";
        inputCommand(str);

    }
}


void SubmitQueue::inputCommand(string line)  {
    //std::cout << line.at(0);
    
    switch(line.at(0)){
        case 'C' : //System Configuration
            systemConfiguration();
            break;
        case 'A' : //Job Arrival
            JobArrival();
            break;
        case 'Q' : //Request for for devices
            requestForDevices();
            break;
        case 'L' : //Release for devices
            releaseForDevices();
            break;
        case 'D' : //Display
            display();
            break;

    }
}

void SubmitQueue::systemConfiguration(){}
void SubmitQueue::JobArrival(){}
void SubmitQueue::requestForDevices(){}
void SubmitQueue::releaseForDevices(){}
void SubmitQueue::display(){}





