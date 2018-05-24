//
//  CPU.cpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


#include "CPU.hpp"
#include "Node.hpp"
#include <iostream>
#include <stdlib.h>
#include "systemConfigurations.h"

CPU::CPU() { //constructor
    first = NULL;
    last = NULL;
    size = 0;
}

void CPU::printLL() {
    cout << "CPU LL: ";
    Node *tmp = first;
    while (tmp != NULL) {
        cout << "[clk: " << tmp->clk_time << ", " << "job: " << tmp->j << " time: " << tmp->r <<"]" << "->";
        tmp = tmp->next;
    }
    
    //   cout << "CPU Count: " << size;
   cout << endl;
}

bool CPU::requestDevices(){
    cout << "requestDevices()" << endl;
    cpu.printLL();
    if(first->s <= serialDevicesAvail){
        serialDevicesAvail -= first->s;
        //first->jobGotDevices = true;
        return true;
    }
    else {
          return false;
    }
    
}

void CPU::addFirst(Node *job) {
    //make a new list of only one node
    size = 1;
    first = job;
    first->next = NULL;
    last = first->next;
}

void CPU::moveToWaitQueue() {
    if(first != NULL) {
        wQueue.addAtEnd(first);
        first = NULL;
        --size;
    }
    //cout << "moveToWaitQueue()" << endl;
    //cout << "CPU: " <<  cpu.inUse << endl;
    cpu.inUse = false;
}

void CPU::moveToRQueue() { //if the job requests & is granted devices
    if(first != NULL) {
        rQueue.addAtEnd(first);
        first = NULL;
        --size;
    }
    
    //cout << "moveToWaitQueue()" << endl;
    //cout << "CPU: " <<  cpu.inUse << endl;
    cpu.inUse = false;
}

void CPU::goToFinishedQueue() {
    if(first != NULL) {
        TimeSliceCounter = TimeSlice;
        cQueue.addAtEnd(first);
        serialDevicesAvail += first->numDevicesUsing;
        first = NULL;
        --size;
    }
    cpu.inUse = false;
}





