//
//  readyQueue.cpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


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
        cout << "[clk: " << tmp->clk_time << ", " << "job: " << tmp->j << " time: " << tmp->r <<"]" << "->";
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
    memAvail -= job->m;
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
        memAvail += first->m;
        if(size > 1){
            Node *tmp = first;
            Node *tmp2 = tmp->next;
            cpu.addFirst(tmp);
            first = tmp2;
            --size;
        }
        else if(first != NULL){
            
            cpu.addFirst(first);
            first = NULL;
            --size;
        }
    }
    
}









