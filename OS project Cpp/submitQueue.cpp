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
#include <sstream>
#include <stdlib.h>
#include "systemConfigurations.h"
using namespace std;

void SubmitQueue::readFile() {
    std::ifstream file("sampleInput.txt");
    std::string str;
    
    
  while (std::getline(file, str)) {
        // Process str
        //std::cout << str;
        //std::cout << "\n";
        inputCommand(str);

    }
}


void SubmitQueue::inputCommand(string line)  {
    //std::cout << line.at(0);
    
    switch(line.at(0)){
        case 'C' : //System Configuration
            systemConfiguration(line);
            break;
        case 'A' : //Job Arrival
            JobArrival(line);
            break;
        case 'Q' : //Request for for devices
            requestForDevices(line);
            break;
        case 'L' : //Release for devices
            releaseForDevices(line);
            break;
        case 'D' : //Display
            display(line);
            break;

    }
}

void SubmitQueue::systemConfiguration(string line) {
    int clock;
    int mem;
    int ser_devices;
    int t_slice;
    
    //erase all the useless text and leave nothing but the values
    line.erase(std::find(line.begin(), line.end(), 'C')); // Erase C
    line.erase(std::find(line.begin(), line.end(), 'M')); // Erase M
    line.erase(std::find(line.begin(), line.end(), 'S')); // Erase M
    line.erase(std::find(line.begin(), line.end(), 'Q')); // Erase Q
    string::iterator x = remove(line.begin(), line.end(), '='); //Erase =
    line.erase(x, line.end());
   
    //setting local vars
    stringstream ss(line);
    ss >> clock >> mem >> ser_devices >> t_slice;
  
    //setting global vars
    clk = clock;
    memory = mem;
    serialDevices = ser_devices;
    TimeSlice = t_slice;
    
   Node sysConfig = *new Node(clock, mem, ser_devices, t_slice);
    
    //test of node
    //printf("clock = %d\n", sysConfig.clk_time);
    //printf("memory = %d\n", sysConfig.m);
    //printf("serial devices = %d\n", sysConfig.s);
    //printf("time quantum = %d\n", sysConfig.q);
    
}
void SubmitQueue::JobArrival(string line){
    int clock;
    int job_num;
    int mem_reqir;
    int serial_reqir;
    int time_runLength;
    int priority;

    //erase all the useless text and leave nothing but the values
    line.erase(std::find(line.begin(), line.end(), 'A')); // Erase A
    line.erase(std::find(line.begin(), line.end(), 'J')); // Erase J
    line.erase(std::find(line.begin(), line.end(), 'M')); // Erase M
    line.erase(std::find(line.begin(), line.end(), 'S')); // Erase S
    line.erase(std::find(line.begin(), line.end(), 'R')); // Erase R
    line.erase(std::find(line.begin(), line.end(), 'P')); // Erase P
    string::iterator x = remove(line.begin(), line.end(), '='); //Erase =
    line.erase(x, line.end());
    
    stringstream ss(line);
    ss >> clock >> job_num >> mem_reqir >> serial_reqir >> time_runLength >> priority;
    
    
    Node jobArrival = *new Node(clock, job_num, mem_reqir, serial_reqir, time_runLength, priority);
    //test of node
    printf("clock = %d\n", jobArrival.clk_time);
    printf("memory required = %d\n", jobArrival.m);
    printf("serial devices required = %d\n", jobArrival.s);
    printf("Job number = %d\n", jobArrival.j);
    printf("units of time needed = %d\n", jobArrival.r);
    printf("priority = %d\n", jobArrival.p);

    
}
void SubmitQueue::requestForDevices(string line){}
void SubmitQueue::releaseForDevices(string line){}
void SubmitQueue::display(string line){}





