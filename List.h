#ifndef LIST_H
#define LIST_H

#include "Node.h"
class Sort;
class List
{
    private:
        int size;
        Node *head;
        Node *tail;

    protected:
        void convertListToArray(int[]);
        void convertArrayToList(int[]);

    public:
        List();
		~List();
        int getSize();
        int isEmpty();
        void push_front(int);
        void push_back(int);
        void pop_front();
        void pop_back();
        void show();
		void sort();
		
};

#endif