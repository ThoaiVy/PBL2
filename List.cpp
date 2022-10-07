#include "List.h"

List::List()
{
    head = tail = NULL;
    this->size = 0;
}

List::~List()
{
	delete head;
	delete tail;
}
int List::getSize()
{
    return this->size;
}

int List::isEmpty()
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

void List::push_front(int k)
{
    Node *p = new Node(k);

    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
    this->size++;
}

void List::push_back(int k)
{
    Node *p = new Node(k);

    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
    this->size++;
}

void List::pop_front()
{
    if (this->size > 0)
    {
        head = head->next;
    }
}


void List::pop_back()
{
    Node *p = new Node();
	for(Node *k = head; k != NULL; k = k->next)
	{
		if (k == tail)
		{
			tail = p;
			tail->next = NULL;
			return;
		}
		p = k;
	}
}

void List::show()
{
    for (Node *p = head; p != NULL; p = p->next)
    {
        cout << p->data << " ";
    }
}

void List::convertListToArray(int arr[])
{
    int i = 0;
    for (Node *p = head; p != NULL; p = p->next)
    {
        arr[i] = p->data;
        i++;
    }
}

void List::convertArrayToList(int arr[])
{
    int index = 0;
    for (Node *p = head; p != NULL; p = p->next)
    {
        p->data = arr[index];
        index++;
    }    
}
void List::sort(){
	List ds;
	int arr[size];
	convertListToArray(arr);
	convertArrayToList(arr);
}


