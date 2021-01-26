#include <iostream>
#include "hashChain.hpp"

//constructor
HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    table = new node*[bsize];
    numOfcolision = 0;
    for(int i = 0; i < bsize; i++)
    {
        table[i]=nullptr;
    }
}


bool HashTable::insertItem(int key)
{
    //makes new node with key value and has it pointing to null
    node* n = new node;
    n->key = key;
    n->next = nullptr;
    //finds the hash value for that key value
    int idx = hashFunction(key);
    //if nothing is there, put node there and return
    if(table[idx]==nullptr)
    {
        table[idx] = n;
        return true;
    }
    //if there is already something there there is a collsion
    numOfcolision++;
    node* crawl = table[idx];
    //crawl through linked list for that value until you get to end
    while(crawl->next!=nullptr)
    {
        numOfcolision++;
        crawl = crawl->next;
    }
    //insert node
    crawl->next = n;
    return true;
}

//returns hash value for key so it knows where to go in table
unsigned int HashTable::hashFunction(int key)
{
    return key%tableSize;
}

//returns the number of collsions
int HashTable::getNumOfCollision()
{
    return numOfcolision;
}

//searchs for a key value
node* HashTable::searchItem(int key)
{
    //checks what index of the table that will be at
    int idx = hashFunction(key);
    node* crawl = table[idx];
    //crawls thorugh linked list until it finds it
    while(crawl->key!=key)
    {
        numOfcolision++;
        crawl = crawl->next;
    }
    //returns that node
    return crawl;
}

