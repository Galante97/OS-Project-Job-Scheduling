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
#include "systemConfigurations.h"

//global system configuation definitions
int clk;
int memory;
int serialDevices;
int TimeSlice;
HoldQueue1 HQ1;


void systemConfig_Test() {
    printf("clock = %d\n", clk);
    printf("memory = %d\n", memory);
    printf("serial devices = %d\n", serialDevices);
    printf("time quantum = %d\n", TimeSlice);
}

int main(int argc, const char * argv[]) {
    //dummy declartion of system configuation
    clk = 0;
    memory = 0;
    serialDevices = 0;
    TimeSlice = 0;

    HQ1 = *new HoldQueue1;
  
    
    SubmitQueue SubmitQueue;
    SubmitQueue.readFile();
    
    HQ1.printLL();
    //cout << HQ1.size;
    //printf("\n");
    
    //test
    //systemConfig_Test();
  

    return 0;
}
