#include "Node.h"

Node::Node()
{
	this->data = 0;
	this->next = NULL;	
} 

Node::Node(int data)
{
    this->data = data;
    this->next = NULL;
}