#include <iostream>
#include <vector>
#include "dtypes.h"
#pragma once 

using namespace std;

void printStringVector(vector<string> vec);

void pringString(string s, int nChar);

void printStatsMap(DTYPE_BYTEPAIR_STATS stats);

void printVocab(DTYPE_BYTEPAIR_VOCAB vocab);

void printVector(vector<int>& vectorArr, int maxLen=10);