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
    cout << "READY QUEUE LL: ";
    Node *tmp = first;
    while (tmp != NULL) {
        cout << "[clk: " << tmp->clk_time << ", " << "j: " << tmp->j << "]" << "->";
        tmp = tmp->next;
    }
    //  cout << "ReadyQueue Count: " << size;
     cout << endl;
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
        
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = job;
        job->next = NULL;
        last = job->next;
    }
    Adding = false;
    if(cpu.first == NULL) { //add ready queue job to cpu
        moveToCPU();
    }

    
}

void readyQueue::moveToCPU() {
    if(cpu.inUse == false && first != NULL){
        memAvail -= first->m;
        if(size > 1){
            Node *tmp = first;
            Node *tmp2 = tmp->next;
            cpu.addFirst(tmp);
            first = tmp2;
            --size;
        }
        else if(first != NULL){
            rQueue.addAtEnd(first);
            first = NULL;
            --size;
        }
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







