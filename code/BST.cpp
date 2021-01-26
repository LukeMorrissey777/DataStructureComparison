#include <iostream>
#include "BST.hpp"

//constructor
BST::BST()
{
    root = nullptr;
}

//helper function for insert
Node* insertHelp(int key, Node* node)
{
    //if the node is greater than the key, look at left child
    if(node->key > key)
    {
        //if no left child that is where new node will go so return the node
        if(node->left==nullptr)
        {
            return node;
        }
        //else call funcion on left node and return that value
        return insertHelp(key,node->left);
    }
    //if node is less than key, look at right child
    //same idea as above
    if(node->right==nullptr)
    {
        return node;
    }
    return insertHelp(key,node->right);
}

//insert function
void BST::insert(int key)
{
    //makes new node and sets both children to NULL
    Node* n = new Node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    //if the BST is empty, the inserted value is now the root
    if(root == nullptr)
    {
        root = n;
        return;
    }

    //call the helper funciton on the root which returns parent pointer
    Node* parent = insertHelp(key,root);
    //inserts to left if it is less than parent, right if more
    if(parent->key > key)
    {
        parent->left = n;
    }
    else
    {
        parent->right = n;
    }
}

//seach helper function
Node* searchHelp(int key, Node* node)
{
    //if node is nullpointer key wasn't found
    if(node==nullptr)
    {
        return nullptr;
    }
    //if key is node's key return node
    if(node->key==key)
    {
        return node;
    }
    //if key is less than nodes key call funtion on left child
    if(node->key>key)
    {
        return searchHelp(key,node->left);
    }
    //else call function on right child
    return searchHelp(key,node->right);
}


Node* BST::search(int key)
{
    //use helper function on root and return that pointer
    return searchHelp(key,root);
}

void printHelp(Node* node)
{
    //if node is null pointer return
    if(node==nullptr)
    {
        return;
    }
    //call function on left child
    printHelp(node->left);
    //print node
    std::cout << node->key << " -> ";
    //call function on right child
    printHelp(node->right);
}

//print function 
void BST::print()
{
    //call print helper function on root
    printHelp(root);
}

int levelHelp(Node* node)
{
    //if node is null return 0
    if(node==nullptr)
    {
        return 0;
    }
    //call function on left and right child
    int l = levelHelp(node->left);
    int r = levelHelp(node->right);
    //return 1 plus whichever is greater
    if(l>r)
    {
        return 1+l;
    }
    return 1+r;
}

//function to see how tall BST is
int BST::levels()
{
    return levelHelp(root);
}