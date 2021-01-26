#include <iostream>
#include "LL.hpp"

//constructor
LL::LL()
{
    head = nullptr;
}

//insert
void LL::insert(int key)
{
    //makes new node with the key value
    Node* n = new Node;
    n->key = key;
    //if the list is empty this becomes the head
    if(head == nullptr)
    {
        n->next = nullptr;
        head = n;
        return;
    }

    //create a crawler node to search for end of linked list
    Node* crawl = head;
    while(crawl->next!=nullptr)
    {
        crawl = crawl -> next;
    }
    //Insert new node at end of linked list
    crawl->next = n;
    n->next = nullptr;
}

Node* LL::search(int key)
{
    //Have a crawler that goes to next node until key is found and returns that pointer
    Node* crawl = head;
    while(crawl->key!=key)
    {
        crawl = crawl->next;
    }
    return crawl;
}

//prints values of linked list from head to tail
void LL::print()
{
    Node* crawl = head;
    while(crawl!=nullptr)
    {
        std::cout << crawl->key << " -> ";
        crawl = crawl->next;
    }
    std::cout << std::endl;
}