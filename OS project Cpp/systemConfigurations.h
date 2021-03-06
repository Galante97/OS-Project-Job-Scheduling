//
//  systemConfigurations.h
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


#ifndef systemConfigurations_h
#define systemConfigurations_h

#include "HoldQueue1.hpp"
#include "HoldQueue2.hpp"
#include "readyQueue.hpp"
#include "waitQueue.hpp"
#include "CPU.hpp"
#include "CompleteQueue.hpp"

extern int clk;
extern int memTotal;
extern int memAvail;
extern int serialDevicesTotal;
extern int serialDevicesAvail;
extern int TimeSlice;
extern int TimeSliceCounter;


const  int SYSTEM_CONFIG = 0;
const  int JOB_ARRIVAL = 1;
const  int REQUEST_FOR_DEVICES = 2;
const  int RELEASE_FOR_DEVICES = 3;
const  int DISPLAY = 4;



extern HoldQueue1 HQ1; //linked list 1 SJF
extern HoldQueue2 HQ2; //linked list 2 FIFO
extern readyQueue rQueue;  //ready queue
extern CPU cpu; //CPU
extern waitQueue wQueue; //waitQueue
extern CompleteQueue cQueue; //CompleteQueue

#endif /* systemConfigurations_h */

