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
    // printf("HQ1 LL: ");
    Node *tmp = first;
    while (tmp != NULL) {
        cout << "[clk: " << tmp->clk_time << ", " << "j: " << tmp->j << "]" << "->";
        tmp = tmp->next;
    }
    cout << endl;
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

void HoldQueue1::addInOrder(Node *job) {
    if(size == 0) {
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
