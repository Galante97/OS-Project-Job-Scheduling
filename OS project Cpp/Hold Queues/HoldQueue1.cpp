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
     printf("\n");
     //cout << "HQ1 Count: " << HQ1.size;
     //cout << endl;
}

void HoldQueue1::addFirst(Node *job) {
    //make a new list of only one node
    size = 1;
    first = job;
    first->next = NULL;
    last = first->next;    
    
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
        last = job; //fixed an error here
        
    }
    HQ1.moveToRQueue(); //moves to ready queue if ready

    
}

void HoldQueue1::addInOrder(Node *job) {
    if(size == 0){
        addFirst(job);
    }
    else{
        size++;
        Node *temp1 = first;
        Node *temp2 = first;
        if(temp2->r > job->r){
            job->next = temp2;
            first = job;
        }
        else if(last->r <= job->r){
            temp1 = last;
            temp1->next = job;
            job->next = NULL;
            last = job;
        }
        else{
            while(temp2 != last && temp2 < job){
                temp2 = temp2->next;
                if(temp2->r > job->r){
                    job->next = temp2;
                    temp1->next = job;
                }
                else{
                    temp1 = temp1->next;
                }
            }
            
        }
    }
}


void HoldQueue1::moveToRQueue() {
    //REMOVE BASED ON SORTING
    if (first->m <= memory) {
        if(first != NULL) {
            Node *tmp = first;
            Node *tmp2 = tmp->next;
            rQueue.addAtEnd(tmp);
            first = tmp2;
            --size;
        }
    } else{
        cout << "not enough memory \n";
    }
}

    
    

