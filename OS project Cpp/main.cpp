//
//  main.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/8/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#include <iostream>
#include "submitQueue.hpp"
#include "systemConfigurations.h"

//global system configuation definitions
int clk;
int memory;
int serialDevices;
int TimeSlice;

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
    
    SubmitQueue SubmitQueue;
    SubmitQueue.readFile();
    
    //test
    systemConfig_Test();
  

    return 0;
}
