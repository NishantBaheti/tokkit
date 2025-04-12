#include <iostream>
#include <fstream>
#include "dtypes.h"
#include "data.h"

using namespace std;

std::vector<int> data::dataLoader(string filepath)
{
    fstream corpusFile;
    // load file as utf-8 encoded string
    locale::global(locale("en_US.UTF-8"));
    corpusFile.open(filepath, ios::in);
    vector<int> corpus;
    if (!corpusFile)
    {
        cout << "Error opening file" << endl;
        return {};
    }
    else
    {
        string line;
        while (getline(corpusFile, line))
        {
            for (char c : line)
            {
                corpus.push_back(c);
            }
        }
    }
    corpusFile.close();
    return corpus;
}

void data::dataSaver(std::vector<int> &corpus, string filepath)
{
    fstream corpusFile;
    // load file as utf-8 encoded string
    locale::global(locale("en_US.UTF-8"));
    corpusFile.open(filepath, ios::out);
    if (!corpusFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    else
    {
        for (int i : corpus)
        {
            corpusFile << static_cast<char>(i);
        }
    }
    corpusFile.close();
}
