#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node* next;
        Node();
        Node(int);
};
#endif