//
//  CompleteQueue.cpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


#include "CompleteQueue.hpp"
#include "systemConfigurations.h"
#include "Node.hpp"
#include <iostream>
#include <stdlib.h>

CompleteQueue::CompleteQueue() { //constructor
    first = NULL;
    last = NULL;
    size = 0;
}

/*CompleteQueue::~CompleteQueue() { //destructor
 Node *tmp = first;
 while (first != NULL) {
 tmp = first->next;
 delete first;
 first = tmp;
 size--;
 }
 first = NULL;
 last = NULL;
 }*/

void CompleteQueue::printLL() {
    cout << "CompletedQueue LL: ";
    Node *tmp = first;
    while (tmp != NULL) {
        cout << "[clk: " << tmp->clk_time << ", " << "j: " << tmp->j << " type: " << tmp->nType << "]" << "->";
        tmp = tmp->next;
    }
    
    //cout << "HQ1 Count: " << HQ1.size;
    cout << endl;
}

void CompleteQueue::addFirst(Node *job) {
    //make a new list of only one node
    size = 1;
    first = job;
    first->next = NULL;
    last = first->next;
    
}

void CompleteQueue::addAtEnd(Node *job) {
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


