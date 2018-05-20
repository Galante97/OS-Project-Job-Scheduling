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
int memory;
int serialDevices;
int TimeSlice;
HoldQueue1 HQ1;
HoldQueue2 HQ2;
readyQueue rQueue;
CPU cpu;
waitQueue wQueue;


void systemConfig_Test() {
    printf("clock = %d\n", clk);
    printf("memory = %d\n", memory);
    printf("serial devices = %d\n", serialDevices);
    printf("time quantum = %d\n", TimeSlice);
}

void pause(int dur) { //real life pause for testing only
    int temp = time(NULL) + dur;
    while(temp > time(NULL));
}

int main(int argc, const char * argv[]) {
    //dummy declartion of system configuation
    clk = 0;
    memory = 0;
    serialDevices = 0;
    TimeSlice = 0;

    //create Queues
    HQ1 = *new HoldQueue1;
    HQ2 = *new HoldQueue2;
    rQueue = *new readyQueue;
    cpu = *new CPU;
    wQueue = *new waitQueue;
    
    SubmitQueue SubmitQueue;
    
    //open file
    std::ifstream file("sampleInput.txt");
    std::string str;
    
    //main loop
    while (std::getline(file, str)) { //iterate through each "Job"
        while(!SubmitQueue.checkCLKTime(str)) { //this is a "wait" while loop, if clk doesnt equal clock time
            clk++; //change later to include time slice
            
            HQ1.printLL();
            rQueue.printLL();
            cpu.printLL();
            wQueue.printLL();
            
            if(cpu.first != NULL) {
                if (cpu.first->r > 0 && cpu.first->jobGotDevices) { //has devices and needs to run
                    cpu.first->r--;
                } else { //go to wait queue, no devices
                    
                    
                    
                    if (cpu.first->nType == JOB_ARRIVAL) {
                        cpu.moveToWaitQueue();
                    } else if (cpu.first->nType == REQUEST_FOR_DEVICES) {
                        wQueue.findJobAndMoveToReady(cpu.first->j);
                        
                    }
                    
                }
                
                   // cout << cpu.first->r << endl;
                
               // if (cpu.first->r == 0) { //job is done
                    //go to finished queue
               // }
            }
            if(file.eof()) { //end of file stop
                break;
            }
           
            //cout << "CLK: " << clk << "\n";
           // HQ1.printLL();
           // rQueue.printLL();
        }
        SubmitQueue.inputCommand(str); //this only runs when the clock matches the correct time in the line
    }
    
    
    //rQueue.moveToCPU();
    HQ1.printLL();
    rQueue.printLL();
    cpu.printLL();
    wQueue.printLL();
    


    
    //unfilled for now
    //HQ2.printLL();
    //cout << "HQ2 count: " << HQ2.size;
    //printf("\n");
    
    //test
    //systemConfig_Test();
  

    return 0;
}
