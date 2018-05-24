//
//  HoldQueue2.cpp
//  OS project Cpp
//
//
//  Created by James Galante, Natatie Ayling and Josh Weinick


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
    cout << "HQ2 LL: ";
    Node *tmp = first;
    while (tmp != NULL) {
        cout << "[clk: " << tmp->clk_time << ", " << "j: " << tmp->j << "]" << "->";
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
    }
 

}


void HoldQueue2::moveToRQueue() {
    if(first != NULL && first->m < memAvail){ //should only move to RQ if there's space in mem
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

