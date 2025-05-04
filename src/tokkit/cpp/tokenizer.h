#include <string>
#include <vector>
#include "dtypes.h"
#pragma once

using namespace std;

namespace bytepairtokenizer {
    class BytePairTokenizer {
        public:
            BytePairTokenizer();
            ~BytePairTokenizer();
            DTYPE_BYTEPAIR_VOCAB vocab;
            DTYPE_BYTEPAIR_REV_VOCAB revVocab;
            int nextVocabIndex = 256;
            int vocabSize = 256;
            int size();
            void fit(vector<int>& corpus, int maxVocabSize, int nIter);
            vector<int> encode(string s);
            vector<int> encodeCorpus(vector<int>& corpus);
            string decode(vector<int> encoded);
            void save(const string& filepath);
            void load(const string& filepath);
    };
}