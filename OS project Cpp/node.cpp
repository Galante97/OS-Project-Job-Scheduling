//
//  node.cpp
//  OS project Cpp
//
//  Created by James Galante on 5/9/18.
//  Copyright © 2018 James Galante. All rights reserved.
//

#include "node.hpp"
#include <iostream>
#include <string>
using namespace std;

Node::Node(int clk, int M, int S, int Q) { //System Configuration
    next = NULL;
    //prev = NULL;
    
    clk_time = clk;
    m = M;
    s = S;
    q = Q;
    
}

Node::Node(int clk, int J, int M, int S, int R, int P) { //Job arrival
    next = NULL;
    //prev = NULL;
    
    clk_time = clk;
    j = J;
    m = M;
    s = S;
    r = R;
    p = P;
}

Node::Node(int clk, int J, int D) { //Request for device OR release for device
    next = NULL;
    //prev = NULL;
    
    clk_time = clk;
    j = J;
    d = D;
}

Node::Node(int clk) { //display
    next = NULL;
    //prev = NULL;
    
    clk_time = clk;

}



