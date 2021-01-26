#ifndef BST_H
#define BST_H
#include <iostream>

//node that stores key and pointer to left and right child
struct Node{
    int key;
    Node* left;
    Node* right;
};

//BST class
class BST
{
private:
    Node* root;
public:
    BST();
    void insert(int);
    Node* search(int);
    void print();
    int levels();
};


#endif