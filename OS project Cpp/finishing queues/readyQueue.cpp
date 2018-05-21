//
//  readyQueue.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/15/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#include "readyQueue.hpp"
#include "Node.hpp"
#include <iostream>
#include <stdlib.h>
#include "systemConfigurations.h"

readyQueue::readyQueue() { //constructor
    first = NULL;
    last = NULL;
    size = 0;
}


void readyQueue::printLL() {
    printf("READY QUEUE LL: ");
    Node *tmp = first;
    while (tmp != NULL) {
        cout << "[clk: " << tmp->clk_time << ", " << "j: " << tmp->j << "]" << "->";
        tmp = tmp->next;
    }
    printf("\n");
  //  cout << "ReadyQueue Count: " << size;
  //  cout << endl;
}

void readyQueue::addFirst(Node *job) {
    //make a new list of only one node
    size = 1;
    first = job;
    first->next = NULL;
    last = first->next;
    
}

void readyQueue::addAtEnd(Node *job) {
    Adding = true;
    //add a new node to the end of the list
    if (size == 0) {
        addFirst(job);
    } else {
        size++;
        
        Node *temp = first;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = job;
        job->next = NULL;
        last = job->next;
    }
    moveToCPU();
    Adding = false;
}


void readyQueue::moveToCPU() {
    cout << "moveToCPU()" << endl;
  //  cout << "RE: " <<  cpu.inUse << endl;
  //  rQueue.printLL();
  //  cpu.printLL();
  //  wQueue.printLL();
  //  printf("\n");
//
    
    if (cpu.inUse == false) {
        if(first != NULL) {
            Node *tmp = first;
            Node *tmp2 = tmp->next;
            cpu.addFirst(tmp);
            first = tmp2;
            --size;
            cpu.inUse = true;
        }
        
        
    } else {
        //cout << "not enough memory \n";
    }
}



/*int *readyQueue::getContentsForJSON() {
    Node *tmp = first;
//    while (tmp != NULL) {
//        cout << "[clk: " << tmp->clk_time << ", " << "j: " << tmp->j << "]" << "->";
//        tmp = tmp->next;
//    }
    
    int r[3] = {7,8,9};
    return *r;
}*/







