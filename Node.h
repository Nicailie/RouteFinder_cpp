//
// Created by user on 29/11/2022.
//
#ifndef INDIVIDUAL_PROJECT_NODE_H
#define INDIVIDUAL_PROJECT_NODE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "Readfile.h"
#include "Airports.h"
/**This is the head file that stores the class Node, state as when you are currently are
 * and the parent where you are coming at
 * and the path cost, the number it took to get to your destination.**/

#include "Route.h"
#include "Airlines.h"
using namespace std;
class Node {
public :
    string state;
    string parent;
    int path_cost;

public:
    Node(string state){
        this->state = state;
        this->parent = nullptr;
        this->path_cost = 0;
    }
    Node(string state, string parent, int path_cost){
        this -> state = state;
        this-> parent  = parent;
        this -> path_cost = path_cost;
    }
};
#endif //INDIVIDUAL_PROJECT_NODE_H
