#include <iostream>
#include "dtypes.h"
#include "data.h"
#include "tokenizer.h"

using namespace std;

int main()
{   
    string path = "/workspaces/tokkit/datasets/raw/combined.txt";
    std::vector<int> corpus = data::dataLoader(path);
    std::cout << corpus.size() << endl;
    // pringString(corpus, 1000);

    bytepairtokenizer::BytePairTokenizer bpe;
    bpe.fit(corpus, 1000, 100);
    std::vector<int> encoded = bpe.encode("Hello My Name is Nishant");
    string decoded = bpe.decode(encoded);
    std::cout << decoded << endl;
    data::dataSaver(corpus, "/workspaces/tokkit/datasets/processed/merged_data.txt");
    return 0;
}
