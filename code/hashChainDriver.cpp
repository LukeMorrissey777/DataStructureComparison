#include <iostream>
#include "hashChain.hpp"
#include <fstream>
#include <sstream>
#include <random>
#include <chrono>




int main(int argc, char** argv)
{
    srand(time(NULL));
    if(argc == 1)
    {
        return -1;
    }
    //read in test data to an array
    int testData[40000];
    std::ifstream iFile(argv[1]);

    if(iFile.is_open())
    {
        int count = 0;
        std::string line;
        std::string num;
        while(std::getline(iFile,line))
        {
            std::stringstream ss(line);
            while(std::getline(ss,num,','))
            {
                testData[count] = stoi(num);
                count++;
            }
        }
    }
    iFile.close();

    //initalize variables and hashtable
    int count = 0;
    int numDat = 0;
    float insert[400];
    float search[400];
    int insertCol[400];
    int searchCol[400];
    HashTable uspsData(40009);
    int prevCol = 0;
    //loop through all the data, 100 at a time
    while(count < 400)
    {
        //time inserting
        auto start = std::chrono::high_resolution_clock::now();
        std::ios_base::sync_with_stdio(false);
        //insert 100 pieces of data
        while((numDat-100*count)<100)
        {
            uspsData.insertItem(testData[numDat]);
            numDat++;
        }
        auto end = std::chrono::high_resolution_clock::now();
        float time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
        time_taken *= 1e-5; 
        //log insert time
        insert[count] = time_taken;
        int currCol = uspsData.getNumOfCollision();
        //log number of collisions in the 100 insertions
        insertCol[count] = currCol-prevCol;
        prevCol = currCol;
        int numel = 100*(count+1);
        //times searching
        auto start2 = std::chrono::high_resolution_clock::now();  
        for(int i = 0; i < 100;i++)
        {   
            //search for random data that has already been inserted
            int x = rand()%numel;
            uspsData.searchItem(testData[x]);
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        float time_taken2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count(); 
        time_taken2 *= 1e-5; 
        //log search time
        search[count] = time_taken2;
        currCol = uspsData.getNumOfCollision();
        //log number of collisions in the 100 searches
        searchCol[count] = currCol-prevCol;
        prevCol = currCol;
        count++;
        
    }
    //print last insert and search time
    std::cout << "Last insert: " << insert[399] << std::endl;
    std::cout << "Last search: " << search[399] << std::endl;

    //uspsData.printTable();

    //checks to see if it works
    node* s = uspsData.searchItem(testData[34978]);
    std::cout << "expected: " << testData[34978] << std::endl << "got: "<< s->key << std::endl;


    //log insert and search times to csv
    std::ofstream insertTimes("Hi.csv");
    for(int i = 0; i < 399; i++)
    {
        insertTimes << insert[i]<< ",";
    }
    insertTimes << insert[399];

    std::ofstream searchTimes("Hs.csv");
    for(int i = 0; i < 399; i++)
    {
        searchTimes << search[i]<< ",";
    }
    searchTimes << search[399];

    //log insert and search collisions in csv
    // std::ofstream iCol("insert_data.csv");
    // for(int i = 0; i < 399; i++)
    // {
    //     iCol << insertCol[i]<< ",";
    // }
    // iCol << insertCol[399];

    // std::ofstream sCol("search_data.csv");
    // for(int i = 0; i < 399; i++)
    // {
    //     sCol << searchCol[i]<< ",";
    // }
    // sCol << searchCol[399];

    

    // insertTimes.close();
    // searchTimes.close();
    // iCol.close();
    // sCol.close();
}