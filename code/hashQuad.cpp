#include <iostream>
#include "hashProbing.hpp"
#include <math.h>

//constructor
HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    numOfcolision = 0;
    table = new int[bsize];
    for(int i = 0; i < bsize; i++)
    {
        table[i]=-1;
    }
}

//insert a key value
bool HashTable::insertItem(int key)
{
    //get index from hash function
    int idx = hashFunction(key);
    //if empty insert
    if(table[idx]==-1)
    {
        table[idx] = key;
        return true;
    }
    //else quadratically probe until you find an openening
    int p = 1;
    int currIdx = idx +p;
    while(table[currIdx%tableSize]!=-1)
    {
        numOfcolision++;
        p++;
        currIdx = idx + pow(p,2);
    }
    table[currIdx%tableSize]=key;
    return true;
}

//hashfunction to get hash value
unsigned int HashTable::hashFunction(int key)
{
    return key%tableSize;
}

//print the table
void HashTable::printTable()
{
    for(int i = 0; i < tableSize;i++)
    {
        std::cout << table[i] << " -> ";
    }
}

//return number of collisions
int HashTable::getNumOfCollision()
{
    return numOfcolision;
}

//search for item
int HashTable::searchItem(int key)
{
    //get index from hash function
    int idx = hashFunction(key);
    //if it is there return that index
    if(table[idx]==key)
    {
        return idx;
    }
    //probe quadratically until you find it
    int p = 1;
    int currIdx = idx +p;
    while(table[currIdx%tableSize]!=key)
    {
        numOfcolision++;
        p++;
        currIdx = idx + pow(p,2);
    }
    return currIdx%tableSize;
}
//return value at index of hashtable
int HashTable::numAt(int idx)
{
    return table[idx];
}