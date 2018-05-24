//
//  submitQueue.cpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick

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
            cout << "C" << endl;
            systemConfiguration(line);
            break;
        case 'A' : //Job Arrival
            cout << "A" << endl;
            JobArrival(line);
            break;
        case 'Q' : //reqeust
            cout << "Q" << endl;
            JobArrival(line);
            break;
        case 'L' : //realase
            cout << "L" << endl;
            JobArrival(line);
            break;
        case 'D' : //Display
            cout << "D" << endl;
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
    TimeSliceCounter = t_slice;
    

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
    
    if(mem_reqir <= memTotal && serial_reqir <= serialDevicesTotal){
        Node *jobArrival = new Node(JOB_ARRIVAL, clock, job_num, mem_reqir, serial_reqir, time_runLength, priority);
        if(mem_reqir <= memAvail) {
            rQueue.addAtEnd(jobArrival);
        } else if(priority == 1)
            HQ1.addInOrder(jobArrival);
        else
            HQ2.addAtEnd(jobArrival);
        
    }
    
}

void SubmitQueue::deviceRequest(string line){
    int clock;
    int job_num;
    int device_num;
    
    //erase all the useless text and leave nothing but the values
    line.erase(std::find(line.begin(), line.end(), 'Q')); // Erase Q
    line.erase(std::find(line.begin(), line.end(), 'J')); // Erase J
    line.erase(std::find(line.begin(), line.end(), 'D')); // Erase D
    string::iterator x = remove(line.begin(), line.end(), '='); //Erase =
    line.erase(x, line.end());
    
    stringstream ss(line);
    ss >> clock >> job_num >> device_num;
    
    if(cpu.first->j == job_num){
        cpu.first->numDevicesRequested += device_num;
        if(serialDevicesAvail < device_num)
            cpu.moveToWaitQueue();
        else{
            serialDevicesAvail -= device_num;
            cpu.first->numDevicesUsing += device_num;
            cpu.moveToRQueue();
        }
    }
}

void SubmitQueue::deviceRelease(string line){
    int clock;
    int job_num;
    int device_num;
    
    //erase all the useless text and leave nothing but the values
    line.erase(std::find(line.begin(), line.end(), 'L')); // Erase L
    line.erase(std::find(line.begin(), line.end(), 'J')); // Erase J
    line.erase(std::find(line.begin(), line.end(), 'D')); // Erase D
    string::iterator x = remove(line.begin(), line.end(), '='); //Erase =
    line.erase(x, line.end());
    
    stringstream ss(line);
    ss >> clock >> job_num >> device_num;
    
    if(cpu.first->j == job_num){
        serialDevicesAvail += device_num;
        cpu.first->numDevicesUsing -= device_num;
    }
    
}

void SubmitQueue::display(string line){
    int clock;
    
    //erase all the useless text and leave nothing but the values
    line.erase(std::find(line.begin(), line.end(), 'D')); // Erase D
    
    stringstream ss(line);
    ss >> clock;
    
    if (clock == 9999) { //dump system
        HQ1.first = NULL;
        HQ2.first = NULL;
        wQueue.first = NULL;
        rQueue.first = NULL;
        cpu.first = NULL;
        cQueue.first = NULL;
    }
    printFiles();
    cout << "JSON FILE CREATED" << endl;
}


void SubmitQueue::printFiles() {
    string outputName = "Output_time_" + std::to_string(clk) + ".json";
    ofstream f(outputName);
   
 
    f << "Current_time: " << clk << endl;
    f << "Total Memory: " << memTotal << endl;
    f << "Available Memory: " << memAvail << endl;
    f << "Total Devices: " << serialDevicesTotal << endl;
    f << "Available Devices: " << serialDevicesAvail << endl;
    f << "Quantum: " << TimeSlice << endl;
    if (cpu.first != NULL)
        f << "CPU:" << cpu.first->j << endl;
    else
         f << "CPU:" << endl;
    f << "Ready Queue: " << endl;
    Node *tmp = rQueue.first;
    while (tmp != NULL) {
        f << tmp->j;
        f << "," << endl;
        tmp = tmp->next;
    }
    f << endl;
    f << "Wait Queue: " << endl;
    Node *tmp2 = wQueue.first;
    while (tmp2 != NULL) {
        f << tmp2->j;
        f << "," << endl;
        tmp2 = tmp2->next;
    }
    f << endl;
    f << "Hold Queue 2: " << endl;
    Node *tmp3 = HQ2.first;
    while (tmp3 != NULL) {
        f << tmp3->j;
        f << "," << endl;
        tmp3 = tmp3->next;
    }
    f << endl;
    f << "Hold Queue 1: " << endl;
    Node *tmp4 = HQ1.first;
    while (tmp4 != NULL) {
        f << tmp4->j;
        f << "," << endl;
        tmp4 = tmp4->next;
    }
    f << endl;
    f << "Complete Queue: " << endl;
    Node *tmp5 = cQueue.first;
    while (tmp5 != NULL) {
        f << tmp5->j;
        f << "," << endl;
        tmp5 = tmp5->next;

    }
    f << endl;
    f << "Wait Queue: " << endl;
    Node *tmp6 = wQueue.first;
    while (tmp6 != NULL) {
        f << tmp6->j;
        f << "," << endl;
        tmp6 = tmp6->next;
        
    }
    f << endl;
    f << "JOBS: ";
    Node *tmp7 = rQueue.first;
    while (tmp7 != NULL) {
        f << "{ " << endl;
        f << "Arrival_time: " << tmp7->clk_time << endl;
        f << "devices_allocated: " << tmp7->s << endl;
        f << "ID: " << tmp7->j << endl;
        f << "remaining_time: " << tmp7->r << endl;
        f << " }" << endl;
        tmp7 = tmp7->next;
    }
    f << endl;
    Node *tmp8 = wQueue.first;
    while (tmp8 != NULL) {
        f << "{ " << endl;
        f << "Arrival_time: " << tmp8->clk_time << endl;
        f << "devices_allocated: " << tmp8->s << endl;
        f << "ID: " << tmp8->j << endl;
        f << "remaining_time: " << tmp8->r << endl;
        f << " }" << endl;
        tmp8 = tmp8->next;
    }
    f << endl;
    Node *tmp9 = wQueue.first;
    while (tmp9 != NULL) {
        f << "{ " << endl;
        f << "Arrival_time: " << tmp9->clk_time << endl;
        f << "devices_allocated: " << tmp9->s << endl;
        f << "ID: " << tmp9->j << endl;
        f << "remaining_time: " << tmp9->r << endl;
        f << " }" << endl;
        tmp9 = tmp9->next;
    }
    f << endl;
    Node *tmp10 = HQ1.first;
    while (tmp10 != NULL) {
        f << "{ " << endl;
        f << "Arrival_time: " << tmp10->clk_time << endl;
        f << "devices_allocated: " << tmp10->s << endl;
        f << "ID: " << tmp10->j << endl;
        f << "remaining_time: " << tmp10->r << endl;
        f << " }" << endl;
        tmp10 = tmp10->next;
    }
    f << endl;
    Node *tmp11 = cQueue.first;
    while (tmp11 != NULL) {
        f << "{ " << endl;
        f << "Arrival_time: " << tmp11->clk_time << endl;
        f << "devices_allocated: " << tmp11->s << endl;
        f << "ID: " << tmp11->j << endl;
        f << "remaining_time: " << tmp11->r << endl;
         f << " }" << endl;
        tmp11 = tmp11->next;
        
    }
    f << endl;
    Node *tmp12 = wQueue.first;
    while (tmp12 != NULL) {
        f << "{ " << endl;
        f << "Arrival_time: " << tmp12->clk_time << endl;
        f << "devices_allocated: " << tmp12->s << endl;
        f << "ID: " << tmp12->j << endl;
        f << "remaining_time: " << tmp12->r << endl;
        f << " }" << endl;
        tmp12 = tmp12->next;
        
    }
    
    
    
}




