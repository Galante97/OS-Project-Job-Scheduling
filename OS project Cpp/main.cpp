//
//  main.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/8/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#include <iostream>
#include "submitQueue.hpp"
#include "HoldQueue1.hpp"
#include "HoldQueue2.hpp"
#include "readyQueue.hpp"
#include "CPU.hpp"
#include "systemConfigurations.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>

//global system configuation definitions
int clk;
int memTotal;
int memAvail;
int serialDevicesTotal;
int serialDevicesAvail;
int TimeSlice;
int TimeSliceCounter;
HoldQueue1 HQ1;
HoldQueue2 HQ2;
readyQueue rQueue;
CPU cpu;
waitQueue wQueue;
CompleteQueue cQueue;


void systemConfig_Test() {
    cout << "clock = " << clk << endl;
    cout << "memory = " << memTotal << endl;
    cout << "serial devices = " << serialDevicesTotal << endl;
    cout << "time quantum =  " << TimeSlice << endl;
    cout << endl;
}

void printAllLists() {
    cout << "clk: "<< clk << endl;
    cout << "serialDevices: " << serialDevicesAvail;
    HQ1.printLL();
    HQ2.printLL();
    rQueue.printLL();
    cpu.printLL();
    wQueue.printLL();
    cQueue.printLL();
}

void pause(int dur) { //real life pause for testing only
    int temp = time(NULL) + dur;
    while(temp > time(NULL));
}

int main(int argc, const char * argv[]) {
    //dummy declaration of system configuration
    clk = 0;
    memTotal = 0;
    memAvail = 0;
    serialDevicesTotal = 0;
    TimeSlice = 0;

    
    
    //create Queues
    HQ1 = *new HoldQueue1;
    HQ2 = *new HoldQueue2;
    rQueue = *new readyQueue;
    cpu = *new CPU;
    wQueue = *new waitQueue;
    cQueue = *new CompleteQueue;

    SubmitQueue SubmitQueue;

//    //tests
//    Node *jobArrival = new Node(JOB_ARRIVAL, 5, 1, 100, 8, 4, 1);
//    Node *jobArrival2 = new Node(JOB_ARRIVAL, 8, 2, 10, 8, 4, 1);
//    Node *jobArrival3 = new Node(JOB_ARRIVAL, 8, 3, 50, 8, 4, 1);
//    Node *jobArrival4 = new Node(JOB_ARRIVAL, 8, 4, 40, 8, 4, 1);
//    Node *jobArrival5 = new Node(JOB_ARRIVAL, 8, 5, 30, 8, 4, 1);
//
//    //in this order
//    //job 2
//    //job 5
//    //job 4
//    //job 3
//    //job 1
//
//    HQ1.addInOrder(jobArrival);
//    HQ1.addInOrder(jobArrival2);
//    HQ1.addInOrder(jobArrival3);
//    HQ1.addInOrder(jobArrival4);
//    HQ1.addInOrder(jobArrival5);
//
//    HQ1.printLL();
    
    //open file
    std::ifstream file("sampleInput.txt");
    std::string str;

    //main loop
 while (std::getline(file, str)) { //iterate through each "Job"
        do { //this is a "wait" while loop, if clk doesnt equal clock time
            clk++; //change later to include time slice -> need to incorporate time slice into all of this
            printAllLists();
            cout << endl;
            
            if(cpu.first == NULL) {
                cpu.inUse = false;
                rQueue.moveToCPU();
            }
            
            if(cpu.first != NULL) { //anything in cpu
                if (cpu.first->r == 0) { //job is done
                    cout << "Job Complete" << endl;
                    cpu.goToFinishedQueue(); //move to finished queue
                    rQueue.moveToCPU();
                    wQueue.moveToRQueue();
                    HQ1.moveToRQueue();
                    HQ2.moveToRQueue();
                    
                } else if (cpu.first->r > 0 && cpu.first->jobGotDevices) { //job HAS DEVICES, now run
                    cpu.first->r--; //running by subracting its r (time)
                    cout << "TimeSliceCounter: " << TimeSliceCounter << endl;
                    TimeSliceCounter--;
                    if (TimeSliceCounter == 0 && cpu.first->r != 0) {
                        TimeSliceCounter = TimeSlice;
                        cpu.moveToRQueue();
                        
                    }
                    
                    cout << "Running on CPU" << endl;
                    
                } else { //job DOES NOT have devices
                    if(cpu.requestDevices()) {
                        cout << "Got availible devices move back to rQueue" << endl;
                        cpu.moveToRQueue();
                    }
                    else {
                        cout << "No availible Devices move to wQueue" << endl;
                        cpu.moveToWaitQueue(); //move to device wait queue if there aren't enough devices available
                    }
                }
                
                if(file.eof()) //end of file stop
                    break;
            }
            
        } while(!SubmitQueue.checkCLKTime(str));
        SubmitQueue.inputCommand(str); //this only runs when the clock matches the correct time in the liner
        
    }
    
    printAllLists();
    
    
    
    //unfilled for now
    //HQ2.printLL();
    //cout << "HQ2 count: " << HQ2.size;
    //printf("\n");
    
    //test
    //systemConfig_Test();
    
    
    return 0;
}
