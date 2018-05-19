//
//  CPU.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/15/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#include "CPU.hpp"
#include "Node.hpp"
#include <iostream>
#include <stdlib.h>

CPU::CPU() { //constructor
    first = NULL;
    last = NULL;
    size = 0;
}


void CPU::printLL() {
    printf("CPU LL: ");
    Node *tmp = first;
    while (tmp != NULL) {
        cout << tmp->clk_time << "->";
        tmp = tmp->next;
    }
    printf("\n");
    cout << "ReadyQueue Count: " << size;
    cout << endl;
}

void CPU::addFirst(Node *job) {
    //make a new list of only one node
    size = 1;
    first = job;
    first->next = NULL;
    last = first->next;
    
}

void CPU::addAtEnd(Node *job) {
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
