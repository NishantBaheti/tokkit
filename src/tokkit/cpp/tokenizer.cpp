#include <iostream>
#include <set>
#include <string>
#include "dtypes.h"
#include "tokenizer.h"

using namespace std;

struct MostFreqPair
{
    DTYPE_BYTEPAIR pair;
    int freq;
};

std::vector<string> splitString(string& str)
{
    std::vector<string> vec;
    string tempString = "";
    for (char c : str)
    {
        if (c != ' ')
        {
            tempString += c;
        }
        else
        {
            vec.push_back(tempString);
            tempString = "";
        }
    }
    vec.push_back(tempString);
    return vec;
}

DTYPE_BYTEPAIR_STATS bytePairStats(vector<int>& corpus)
{
    int sizeOfCorpus = corpus.size();
    DTYPE_BYTEPAIR_STATS stats;
    for (int i = 0; i < sizeOfCorpus - 1; i++)
    {
        DTYPE_BYTEPAIR pair = { corpus[i], corpus[i + 1] };
        if (stats.find(pair) == stats.end())
        {
            stats[pair] = 1;
        }
        else
        {
            stats[pair] += 1;
        }
    }
    return stats;
}

MostFreqPair getMaxFreqPair(DTYPE_BYTEPAIR_STATS stats)
{
    int maxFreq = 0;
    MostFreqPair mostFreqPair;
    DTYPE_BYTEPAIR maxFreqPair = {-1, -1};
    for (const auto& [key, value] : stats)
    {
        if (value > maxFreq)
        {
            maxFreq = value;
            maxFreqPair = key;
        }
    }
    mostFreqPair.freq = maxFreq;
    mostFreqPair.pair = maxFreqPair;
    return mostFreqPair;
}


void updateVocab(DTYPE_BYTEPAIR_VOCAB& vocab, DTYPE_BYTEPAIR_REV_VOCAB& revVocab, DTYPE_BYTEPAIR& pair, int& nextVocabIndex, int& vocabSize)
{
    if (vocab.find(pair) == vocab.end())
    {
        vocab[pair] = nextVocabIndex;
        revVocab[nextVocabIndex] = pair;
        nextVocabIndex++;
        vocabSize++;
    }
}

/// @brief Merge Corpus with vocab of bytepairs
/// @param corpus 
/// @param vocab
void mergeCorpus(vector<int>& corpus, DTYPE_BYTEPAIR_VOCAB& vocab)
{
    while (1)
    {
        vector<int> newCorpus;
        newCorpus.reserve(corpus.size());

        int sizeOfCorpus = corpus.size();
        bool changeFlag = false;
        int i = 0;

        while (i < sizeOfCorpus - 1)
        {
            DTYPE_BYTEPAIR pair = { corpus[i], corpus[i + 1] };
            if (vocab.find(pair) == vocab.end())
            {
                newCorpus.push_back(corpus[i]);
                i += 1;
            }
            else
            {
                changeFlag = true;
                newCorpus.push_back(vocab[pair]);
                i += 2;
            }
        }
        if (i == sizeOfCorpus - 1)
        {
            newCorpus.push_back(corpus[i]);
        }
        if (!changeFlag)
        {
            break;
        }
        corpus = newCorpus;
    }
}

namespace bytepairtokenizer
{
    BytePairTokenizer::BytePairTokenizer() {}
    int BytePairTokenizer::size()
    {
        return vocabSize;
    }
    BytePairTokenizer::~BytePairTokenizer() {}

    /// @brief Fit tokenizer
    /// @param corpus corpus array
    /// @param maxVocabSize Maximum vocab size
    /// @param nIter Maximum number of iterations
    void BytePairTokenizer::fit(vector<int>& corpus, int maxVocabSize, int nIter)
    {
        int originalSize = corpus.size();
        for (int i = 0; i < nIter; i++)
        {
            std::cout << "Iteration " << i + 1 << endl;
            
            DTYPE_BYTEPAIR_STATS stats = bytePairStats(corpus);
            MostFreqPair mostFreqPair = getMaxFreqPair(stats);

            std::cout << "[" << mostFreqPair.pair[0] << " .. " << mostFreqPair.pair[1] << "] -> " << mostFreqPair.freq << endl;

            if (mostFreqPair.freq == 0)
            {
                cout << "Nothing to Merge";
                break;
            }
            updateVocab(this->vocab, revVocab, mostFreqPair.pair, nextVocabIndex, vocabSize);
            std::cout << size() << endl;
            // printVocab(bpe.vocab);
            if (size() >= maxVocabSize)
            {
                break;
            }
            mergeCorpus(corpus, vocab);
            int newSize = corpus.size();
            std::cout << newSize << " " << originalSize << " " << (originalSize - newSize) * 100 / originalSize << "%" << endl;
        }
    }

    vector<int> BytePairTokenizer::encode(string s)
    {
        vector<int> encoded;
        for (unsigned char c : s)
        {
            encoded.push_back(static_cast<int>(c));
        }
        mergeCorpus(encoded, vocab);
        for (int i : encoded)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        return encoded;
    }

    vector<int> BytePairTokenizer::encodeCorpus(vector<int>& corpus)
    {
        mergeCorpus(corpus, vocab);
        return corpus;
    }

    string _decodeRecursive(int token, DTYPE_BYTEPAIR_REV_VOCAB& revVocab)
    {
        if (token < 256)
        {
            return string(1, static_cast<char>(token));
        }
        DTYPE_BYTEPAIR pair = revVocab[token];
        return _decodeRecursive(pair[0], revVocab) + _decodeRecursive(pair[1], revVocab);
    }

    string BytePairTokenizer::decode(vector<int> encoded)
    {
        string decoded = "";
        for (int i : encoded)
        {
            decoded += _decodeRecursive(i, revVocab);
        }
        return decoded;
    }
};