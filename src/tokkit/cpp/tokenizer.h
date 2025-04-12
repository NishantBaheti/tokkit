#include <string>
#include "dtypes.h"

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
            string decode(vector<int> encoded);
    };
}