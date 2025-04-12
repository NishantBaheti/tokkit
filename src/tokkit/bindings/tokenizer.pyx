
from libcpp.string cimport string
from libcpp.vector cimport vector
from tokkit.bindings.tokenizer cimport BytePairTokenizer
from tokkit.bindings.tokenizer cimport dataLoader, dataSaver

cdef class PyBytePairTokenizer:
    cdef BytePairTokenizer c_bpt

    def __init__(self):
        self.c_bpt = BytePairTokenizer()

    @property
    def size(self):
        return self.c_bpt.size()

    def fit(self, vector[int] corpus, int  max_vocab_size, int n_iter):
        self.c_bpt.fit(corpus, max_vocab_size, n_iter)
    
    def encode(self, string input_string):
        return self.c_bpt.encode(input_string)
    
    def decode(self, vector[int] encoded):
        return self.c_bpt.decode(encoded)
    

def data_loader(string filepath):
    return dataLoader(filepath)


def data_saver(vector[int] corpus, string filepath):
    dataSaver(corpus, filepath)