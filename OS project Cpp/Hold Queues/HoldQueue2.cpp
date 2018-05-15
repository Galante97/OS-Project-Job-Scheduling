//
//  HoldQueue2.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/13/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#include "HoldQueue2.hpp"
#include "systemConfigurations.h"
#include "Node.hpp"
#include <iostream>
#include <stdlib.h>

HoldQueue2::HoldQueue2() { //constructor
    first = NULL;
    last = NULL;
    size = 0;
}
/*HoldQueue2::~HoldQueue2() { //destructor
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
void HoldQueue2::printLL() {
    printf("HQ2 LL: ");
    Node *tmp = first;
    while (tmp != NULL) {
        cout << tmp->clk_time << "->";
        tmp = tmp->next;
    }
    cout << endl;
}

void HoldQueue2::addFirst(Node *job) {
    //make a new list of only one node
    size = 1;
    first = job;
    first->next = NULL;
    last = first->next;
    
    moveToRQueue(job);
}

void HoldQueue2::addAtEnd(Node *job) {
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
        
        moveToRQueue(job);
    }
    
}


void HoldQueue2::moveToRQueue(Node *job) {
    if (job->m <= memory) {
        //REMOVE BASED ON SORTING
        printf("Can move to ready queue \n");
    }    
}

