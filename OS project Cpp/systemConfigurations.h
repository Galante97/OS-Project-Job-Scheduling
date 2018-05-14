//
//  systemConfigurations.h
//  OS project Cpp
//
//  Created by James Galante on 5/9/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#ifndef systemConfigurations_h
#define systemConfigurations_h

#include "HoldQueue1.hpp"
#include "HoldQueue2.hpp"

extern int clk;
extern int memory;
extern int serialDevices;
extern int TimeSlice;

extern HoldQueue1 HQ1; //linked list 1 SJF
extern HoldQueue2 HQ2; //linked list 2 FIFO


#endif /* systemConfigurations_h */

