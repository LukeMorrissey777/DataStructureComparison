#include <iostream>
#include "BST.hpp"
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
    //read in all the test data to an array
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

    //intialize the count(iteration we are on), numDat(the number of data we have put in), and 2 arrays for the insert
    //and search times as well as a BST
    int count = 0;
    int numDat = 0;
    float insert[400];
    float search[400];
    BST uspsData;
    //loop through data until count is 400
    while(count < 400)
    {
        //time inserting
        auto start = std::chrono::high_resolution_clock::now();
        std::ios_base::sync_with_stdio(false);
        //loop through 100 pieces of data and insert them
        while((numDat-100*count)<100)
        {
            uspsData.insert(testData[numDat]);
            numDat++;
        }
        auto end = std::chrono::high_resolution_clock::now();
        float time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
        time_taken *= 1e-5; 
        //log insert time
        std::cout << uspsData.levels() << std::endl;
        insert[count] = time_taken;
        int numel = 100*(count+1);
        //time searching
        auto start2 = std::chrono::high_resolution_clock::now();  
        for(int i = 0; i < 100;i++)
        {
            //search for random number already inserted
            int x = rand()%numel;
            uspsData.search(testData[x]);
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        float time_taken2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count(); 
        time_taken2 *= 1e-5;
        //log search time 
        search[count] = time_taken2;
        count++;
        
    }
    //print last search and insert time
    std::cout << "Last insert: " << insert[399] << std::endl;
    std::cout << "Last search: " << search[399] << std::endl;

    //checks to see if it works
    Node* s = uspsData.search(testData[34978]);
    std::cout << "expected: " << testData[34978] << std::endl << "got: "<< s->key << std::endl;

    //uspsData.print();
    //prints how many levels there are
    std::cout << std::endl << uspsData.levels() << std::endl;

    //log data as csv
    std::ofstream insertTimes("BSTi.csv");
    for(int i = 0; i < 399; i++)
    {
        insertTimes << insert[i]<< ",";
    }
    insertTimes << insert[399];

    std::ofstream searchTimes("BSTs.csv");
    for(int i = 0; i < 399; i++)
    {
        searchTimes << search[i]<< ",";
    }
    searchTimes << search[399];

    // insertTimes.close();
    // searchTimes.close();
}
 
