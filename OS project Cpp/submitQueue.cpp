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
#include "json.hpp"

// for convenience
// using json = nlohmann::json;
using namespace std;

void SubmitQueue::inputCommand(string line)  {
    
    switch(line.at(0)){
        case 'C' : //System Configuration
            systemConfiguration(line);
            break;
        case 'A' : //Job Arrival
            JobArrival(line);
            break;
        case 'D' : //Display
            display(line);
            break;
            
    }
}

bool SubmitQueue::checkCLKTime(string line) {
    int clkInLine;
    //erase all the useless text and leave nothing but the values
    line.erase(std::find(line.begin(), line.end(), 'C')); // Erase C
    line.erase(std::find(line.begin(), line.end(), 'M')); // Erase M
    line.erase(std::find(line.begin(), line.end(), 'S')); // Erase S
    line.erase(std::find(line.begin(), line.end(), 'Q')); // Erase Q
    line.erase(std::find(line.begin(), line.end(), 'A')); // Erase A
    line.erase(std::find(line.begin(), line.end(), 'J')); // Erase J
    line.erase(std::find(line.begin(), line.end(), 'R')); // Erase R
    line.erase(std::find(line.begin(), line.end(), 'P')); // Erase P
    line.erase(std::find(line.begin(), line.end(), 'D')); // Erase D
    string::iterator x = remove(line.begin(), line.end(), '='); //Erase =
    line.erase(x, line.end());
    
    //setting local vars
    stringstream ss(line);
    ss >> clkInLine;
    
    if (clkInLine == clk) {
        return true;
    } else {
        return false;
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
    memTotal = mem;
    memAvail = mem;
    serialDevicesTotal = ser_devices;
    serialDevicesAvail = ser_devices;
    TimeSlice = t_slice;
    
    //Node *sysConfig = new Node(clock, mem, ser_devices, t_slice);
    //HQ1.addAtEnd(sysConfig);
    
    //HQ1.addAtFront(*sysConfig);
    
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
    
    cout << "BLAH:" << serialDevicesAvail << endl;
    if(mem_reqir <= memTotal && serial_reqir <= serialDevicesTotal){
        cout << "Good" << endl;
        Node *jobArrival = new Node(JOB_ARRIVAL, clock, job_num, mem_reqir, serial_reqir, time_runLength, priority);
        if(mem_reqir <= memAvail) {
            rQueue.addAtEnd(jobArrival);
        } else if(priority == 1)
            HQ1.addInOrder(jobArrival);
        else
            HQ2.addAtEnd(jobArrival);
        
    }
    
    //test of node
    //    cout << endl;
    //    printf("clock = %d\n", clk);
    //    printf("memory required = %d\n",memory);
    //    printf("serial devices required = %d\n", serialDevices);
    //    printf("units of time needed = %d\n", TimeSlice);
    //    cout << endl;
    
    
}

void SubmitQueue::display(string line){
    int clock;
    
    //erase all the useless text and leave nothing but the values
    line.erase(std::find(line.begin(), line.end(), 'D')); // Erase D
    
    stringstream ss(line);
    ss >> clock;
    
    // printFiles();
    
    //Node *display = new Node(DISPLAY, clock);
    //HQ1.addAtEnd(display);
    
    //test of node
    //printf("clock = %d\n", display.clk_time);
}

/*
 void SubmitQueue::printFiles() {
 //int *array = rQueue.getContentsForJSON();
 for (int i = 2 - 1; i >= 0; i--) {
 cout << "ijenvjn";
 cout << array[i];
 }
 json j2 = {
 {"current_time", clk},
 {"total_memory", memory},
 {"available_memory", memory},
 {"total_devices", serialDevices},
 {"available_devices", serialDevices},
 {"quantum", TimeSlice},
 {"turnaround", " "},
 {"weighted_turnaround", " "},
 {"submitQ", {1, 0, 2}},
 {"holdq2", {1, 0, 2}},
 {"holdq1", {1, 0, 2}},
 {"CompletedQ", {1, 0, 2}},
 {"waitQ", {1, 0, 2}},
 {"Jobs", {{44,4,4}, {1,23,4}}}
 
 };
 
 std::ofstream file("key.json");
 file << j2;
 
 }
 */



