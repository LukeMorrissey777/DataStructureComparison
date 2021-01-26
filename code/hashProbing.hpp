#ifndef HASHPROBING_HPP
#define HASHPROBING_HPP

#include <string>

//hash table class for probing
class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    int* table;
    int numOfcolision =0;
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int numAt(int);
    int getNumOfCollision();

    int searchItem(int key);
};

#endif
