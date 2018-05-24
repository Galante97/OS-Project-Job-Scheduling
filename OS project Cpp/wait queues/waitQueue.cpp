//
//  waitQueue.cpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


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
    cout << "Wait queue LL: " << endl;
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


void waitQueue::moveToRQueue() {
    if(first != NULL && first->numDevicesRequested < serialDevicesAvail && first->m < memAvail){
        if(size > 1){
            Node *tmp = first;
            Node *tmp2 = tmp->next;
            rQueue.addAtEnd(tmp);
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












