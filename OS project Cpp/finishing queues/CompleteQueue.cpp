//
//  CompleteQueue.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/15/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

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
    printf("CompleteQueue LL: ");
    Node *tmp = first;
    while (tmp != NULL) {
        cout << tmp->clk_time << "->";
        tmp = tmp->next;
    }
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


