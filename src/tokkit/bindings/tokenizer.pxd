
from libcpp.string cimport string
from libcpp.vector cimport vector
from libcpp.unordered_map cimport unordered_map
from libcpp.list cimport list

cdef extern from "tokenizer.h" namespace "bytepairtokenizer":
    cdef cppclass BytePairTokenizer:
        BytePairTokenizer() except +
        unordered_map[int, list[int]] vocab
        unordered_map[list[int], int] revVocab
        int nextVocabIndex
        int vocabSize
        int size()
        void fit(vector[int]& corpus, int maxVocabSize, int nIter)
        vector[int] encode(string s)
        string decode(vector[int] encoded)


cdef extern from "data.h" namespace "data":
    cdef vector[int] dataLoader(string filepath)
    cdef void dataSaver(vector[int] corpus, string filepath)