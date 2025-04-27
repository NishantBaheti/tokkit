#include <iostream>
#include "dtypes.h"
#include "data.h"
#include "tokenizer.h"
#include "utils.h"

using namespace std;

int main()
{   
    string path = "/workspaces/tokkit/datasets/raw/combined.txt";
    std::vector<int> corpus = data::dataLoader(path);
    std::cout << corpus.size() << endl;
    // printVector(corpus, 1000);

    bytepairtokenizer::BytePairTokenizer bpe;
    bpe.fit(corpus, 1000, 10);

    corpus = bpe.encodeCorpus(corpus);
    printVector(corpus, 100);
    
    std::vector<int> encoded = bpe.encode("!#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~ ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþ");
    string decoded = bpe.decode(encoded);
    std::cout << decoded << endl;
    data::dataSaver(corpus, "/workspaces/tokkit/datasets/processed/merged_data.txt");
    return 0;
}
