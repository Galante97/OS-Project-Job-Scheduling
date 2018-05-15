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

readyQueue::readyQueue() { //constructor
    first = NULL;
    last = NULL;
    size = 0;
}


void readyQueue::printLL() {
    printf("READY QUEUE LL: ");
    Node *tmp = first;
    while (tmp != NULL) {
        cout << tmp->clk_time << "->";
        tmp = tmp->next;
    }
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

