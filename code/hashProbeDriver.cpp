#include <iostream>
#include "hashProbing.hpp"
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
    //read in all data to an array
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
    //intialize all these variables and a hashtable
    int count = 0;
    int numDat = 0;
    float insert[400];
    float search[400];
    int insertCol[400];
    int searchCol[400];
    HashTable uspsData(40009);
    int prevCol = 0;
    while(count < 400)
    {
        //time inserting
        auto start = std::chrono::high_resolution_clock::now();
        std::ios_base::sync_with_stdio(false);
        //do 100 insertions
        while((numDat-100*count)<100)
        {
            uspsData.insertItem(testData[numDat]);
            numDat++;
        }
        auto end = std::chrono::high_resolution_clock::now();
        float time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
        time_taken *= 1e-5; 
        //log inserttimes
        insert[count] = time_taken;
        int currCol = uspsData.getNumOfCollision();
        //log insert collisions
        insertCol[count] = currCol-prevCol;
        prevCol = currCol;
        int numel = 100*(count+1);
        auto start2 = std::chrono::high_resolution_clock::now();  
        for(int i = 0; i < 100;i++)
        {
            //search random data already inserted
            int x = rand()%numel;
            uspsData.searchItem(testData[x]);
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        float time_taken2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count(); 
        time_taken2 *= 1e-5; 
        //log search time
        search[count] = time_taken2;
        currCol = uspsData.getNumOfCollision();
        //log search collisions
        searchCol[count] = currCol-prevCol;
        prevCol = currCol;
        count++;
        
    }
    //print last insert and search times
    std::cout << "Last insert: " << insert[399] << std::endl;
    std::cout << "Last search: " << search[399] << std::endl;

    //uspsData.printTable();

    //checks to see if it works
    int s = uspsData.searchItem(testData[34978]);
    std::cout << "expected: " << testData[34978] << std::endl << "got: "<< uspsData.numAt(s) << std::endl;


    // std::ofstream insertTimes("insert_data.csv");
    // for(int i = 0; i < 399; i++)
    // {
    //     insertTimes << insert[i]<< ",";
    // }
    // insertTimes << insert[399];

    // std::ofstream searchTimes("search_data.csv");
    // for(int i = 0; i < 399; i++)
    // {
    //     searchTimes << search[i]<< ",";
    // }
    // searchTimes << search[399];

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