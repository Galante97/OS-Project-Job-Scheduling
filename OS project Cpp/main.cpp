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
int serialDevices;
int TimeSlice;
HoldQueue1 HQ1;
HoldQueue2 HQ2;
readyQueue rQueue;
CPU cpu;
waitQueue wQueue;
CompleteQueue cQueue;


void systemConfig_Test() {
    cout << "clock = " << clk << endl;
    cout << "memory = " << memTotal << endl;
    cout << "serial devices = " << serialDevices << endl;
    cout << "time quantum =  " << TimeSlice << endl;
    cout << endl;
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
    serialDevices = 0;
    TimeSlice = 0;
    
    //create Queues
    HQ1 = *new HoldQueue1;
    HQ2 = *new HoldQueue2;
    rQueue = *new readyQueue;
    cpu = *new CPU;
    wQueue = *new waitQueue;
    cQueue = *new CompleteQueue;
    
    SubmitQueue SubmitQueue;
    
    //open file
    std::ifstream file("sampleInput.txt");
    std::string str;
    
    //main loop
    while (std::getline(file, str)) { //iterate through each "Job"
        
        do { //this is a "wait" while loop, if clk doesnt equal clock time
            clk++; //change later to include time slice -> need to incorporate time slice into all of this
            HQ1.printLL();
            rQueue.printLL();
            cpu.printLL();
            wQueue.printLL();
            cQueue.printLL();
            cout << endl;
            
            
            if(cpu.first != NULL) { //anything in cpu
                if (cpu.first->r == 0) { //job is done
                    cpu.goToFinishedQueue(); //move to finished queue
                    wQueue.moveToRQueue();
                    HQ1.moveToRQueue();
                    HQ2.moveToRQueue();
                    rQueue.moveToCPU(); //move the next job  off the ready queue and to cpu
                } else if (cpu.first->r > 0 && cpu.first->jobGotDevices) { //job HAS DEVICES, now run
                    cpu.first->r--; //running by subracting its r (time)
                    
                } else { //job DOES NOT have devices
                    if(cpu.requestDevices())
                        cpu.moveToRQueue();
                    else
                        cpu.moveToWaitQueue(); //move to device wait queue if there aren't enough devices available
                }
                
                if(file.eof()) //end of file stop
                    break;
            }
        } while(!SubmitQueue.checkCLKTime(str));
        SubmitQueue.inputCommand(str); //this only runs when the clock matches the correct time in the line
        
        cout << "clk: "<< clk << endl;
        HQ1.printLL();
        rQueue.printLL();
        cpu.printLL();
        wQueue.printLL();
        cQueue.printLL();
        
        
        
        
        //unfilled for now
        //HQ2.printLL();
        //cout << "HQ2 count: " << HQ2.size;
        //printf("\n");
        
        //test
        //systemConfig_Test();
        
        
        return 0;
    }
}
