//
//  HoldQueue1.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/13/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#include "HoldQueue1.hpp"
#include "systemConfigurations.h"
#include "Node.hpp"
#include <iostream>
#include <stdlib.h>

HoldQueue1::HoldQueue1() { //constructor
    first = NULL;
    last = NULL;
    size = 0;
}
/*HoldQueue1::~HoldQueue1() { //destructor
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
void HoldQueue1::printLL() {
    printf("HQ1 LL: ");
    Node *tmp = first;
    while (tmp != NULL) {
        cout << tmp->clk_time << "->";
        tmp = tmp->next;
    }
    cout << endl;
}

void HoldQueue1::addFirst(Node *job) {
    //make a new list of only one node
    size = 1;
    first = job;
    first->next = NULL;
    last = first->next;
    
    moveToRQueue(job);
}

void HoldQueue1::addAtEnd(Node *job) {
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


void HoldQueue1::moveToRQueue(Node *job) {
    //REMOVE BASED ON SORTING
    if (job->m <= memory) {
        printf("Can move to ready queue \n");
    }
}


    
    

