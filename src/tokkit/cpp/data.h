#include <iostream>
#include <fstream>
#include "dtypes.h"
#pragma once

using namespace std;

namespace data {
    std::vector<int> dataLoader(string filepath);
    void dataSaver(std::vector<int>& corpus, string filepath);
}