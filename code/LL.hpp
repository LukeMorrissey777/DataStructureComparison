#ifndef LL_H
#define LL_H
#include <iostream>
//node to hold key and point to next node
struct Node
{
    int key;
    Node* next;
};

//Linked list class
class LL
{
    public:
        LL();
        void insert(int);
        Node* search(int);
        void print();
    private:
        Node* head;
};




#endif
