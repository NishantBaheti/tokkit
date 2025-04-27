
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
    
    def encode(self, str input_string):
        cdef string c_input_string = input_string.encode("utf-8")
        return self.c_bpt.encode(c_input_string)

    def encode_corpus(self, vector[int] input_corpus):
        return self.c_bpt.encodeCorpus(input_corpus)
    
    def decode(self, vector[int] encoded):
        cdef string decoded  = self.c_bpt.decode(encoded)
        return decoded.decode("utf-8", errors="replace")
    

def data_loader(str filepath):
    cdef string c_filepath = filepath.encode("utf-8")
    return dataLoader(c_filepath)


def data_saver(vector[int] corpus, str filepath):
    cdef string c_filepath = filepath.encode("utf-8")
    dataSaver(corpus, filepath)