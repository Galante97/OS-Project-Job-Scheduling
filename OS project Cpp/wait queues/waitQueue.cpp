//
//  waitQueue.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/15/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#include "waitQueue.hpp"
#include "Node.hpp"
#include <iostream>
#include <stdlib.h>
#include "systemConfigurations.h"

waitQueue::waitQueue() { //constructor
    first = NULL;
    last = NULL;
    size = 0;
}


void waitQueue::printLL() {
    printf("WAIT QUEUE LL: ");
    Node *tmp = first;
    while (tmp != NULL) {
        cout << "[clk: " << tmp->clk_time << ", " << "j: " << tmp->j << "]" << "->";
        tmp = tmp->next;
    }
    printf("\n");
    //cout << "waitQueue Count: " << size;
    //cout << endl;
}

void waitQueue::addFirst(Node *job) {
    //make a new list of only one node
    size = 1;
    first = job;
    first->next = NULL;
    last = first->next;
    
}

void waitQueue::addAtEnd(Node *job) {
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
    
    
}


void waitQueue::findJobAndMoveToReady(int jobNumber) {
    // Store head node
    Node *temp = first;
    Node *prev;
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->j == jobNumber) {
        first = temp->next;   // Changed head
        
        while(rQueue.Adding){} //wait
        temp->jobGotDevices = true;
        cpu.inUse = false; //this frees up the cpu space so the request node will be overwrited
        rQueue.addAtEnd(temp);
        return;
    }
    
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->j != jobNumber) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == NULL) return;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    
    free(temp);  // Free memory
}











