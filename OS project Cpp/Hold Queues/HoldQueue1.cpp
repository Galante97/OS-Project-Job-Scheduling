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
    cout << endl;
    cout << "HQ1 LL: ";
    Node *tmp = first;
    while (tmp != NULL) {
        cout << "[Run time: " << tmp->r << ", " << "j: " << tmp->j << "]" << "->";
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
    last = first;
    
}


/* function to insert a new_node in a list. Note that this
 function expects a pointer to head_ref as this can modify the
 head of the input linked list (similar to push())*/


void HoldQueue1::addInOrder(Node *job) {
    if(size == 0) {
        addFirst(job);
    }
    else{
        size++;
        Node *temp1 = first;
        Node *temp2 = first;
        cout<< "temp1: " << temp1->j << endl;
        cout<< "temp2: " << temp2->j << endl;
        
        
        if(temp2->r > job->r){
            job->next = temp2;
            first = job;
            cout<< "-temp1: " << temp1->j << endl;
            cout<< "-temp2: " << temp2->j << endl;
        }
        else if(last->r < job->r){
            temp1 = last;
            temp1->next = job;
            job->next = NULL;
            last = job;
        } /*else if(last->r == job->r){ //TESTING SORTING BY MEMEORY IF LENGTH IS EQUAL
            if(job->m <= last->m) {
                first = job;
                job->next = temp1;
                temp1 = last;
                temp1->next = NULL;
            }
            
        } */
        else{
            while(temp2 != last && temp2->r < job->r){
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
