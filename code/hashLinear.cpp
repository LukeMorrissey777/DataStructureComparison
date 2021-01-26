#include <iostream>
#include "hashProbing.hpp"

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

//inserts a key value
bool HashTable::insertItem(int key)
{
    //finds index for insertion
    int idx = hashFunction(key);
    //if table is empty insert
    if(table[idx]==-1)
    {
        table[idx] = key;
        return true;
    }
    //else increase the index until you find open slot
    while(table[idx%tableSize]!=-1)
    {
        numOfcolision++;
        idx++;
    }
    table[idx%tableSize]=key;
    return true;
}

//hash function to return hash value
unsigned int HashTable::hashFunction(int key)
{
    return key%tableSize;
}

//prints table
void HashTable::printTable()
{
    for(int i = 0; i < tableSize;i++)
    {
        std::cout << table[i] << " -> ";
    }
}

//gets the number of collisions
int HashTable::getNumOfCollision()
{
    return numOfcolision;
}

//searches for key and returns index of array that it is at
int HashTable::searchItem(int key)
{
    //get index from hash function
    int idx = hashFunction(key);
    //check if that is the key
    if(table[idx]==key)
    {
        return idx;
    }
    //else increase linearly until you find it
    while(table[idx%tableSize]!=key)
    {
        numOfcolision++;
        idx++;
    }
    return idx%tableSize;
}
//function to return key at an index
int HashTable::numAt(int idx)
{
    return table[idx];
}