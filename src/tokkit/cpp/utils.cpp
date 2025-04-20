#include <iostream>
#include <vector>
#include "dtypes.h"

using namespace std;


void printStringVector(vector<string> vec)
{
    for (string s : vec)
    {
        std::cout << s << std::endl;
    }
}

void pringString(string s, int nChar)
{
    int size = s.size();
    int printSize = std::min(size, nChar);
    for (int i = 0; i < printSize; i++)
    {
        std::cout << int(s[i]) << std::endl;
    }
    std::cout << std::endl;
}

void printStatsMap(DTYPE_BYTEPAIR_STATS stats)
{
    // Iterate using C++17 facilities
    for (const auto& [key, value] : stats)
        std::cout << "[" << key[0] << "-" << key[1] << "] = " << value << "; ";
}

void printVocab(DTYPE_BYTEPAIR_VOCAB vocab)
{
    for (const auto& [key, value] : vocab)
        std::cout << "[" << key[0] << "-" << key[1] << "] = " << value << "; ";
}

void printVector(vector<int>& vectorArr, int maxLen)
{
    int arraySize = vectorArr.size();
    int printSize = min(arraySize, maxLen);
    for(int i=0; i<printSize; i++){
        cout << i << " - " << vectorArr[i] << endl;
    }
}