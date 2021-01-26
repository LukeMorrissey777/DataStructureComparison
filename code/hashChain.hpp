#ifndef HASHCHAIN_HPP
#define HASHCHAIN_HPP

#include <string>


using namespace std;

//node that stores key and pointer to next
struct node
{
    int key;
    struct node* next;
};

//hash table class
class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision =0;
    node* createNode(int key, node* next);
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    node* searchItem(int key);
};

#endif
