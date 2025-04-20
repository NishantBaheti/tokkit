from tokkit import PyBytePairTokenizer, data_loader


corpus = data_loader(
    b"/workspaces/tokkit/datasets/raw/combined.txt"
)

tokenizer = PyBytePairTokenizer()

tokenizer.fit(corpus, 10000, 10)

corpus_transformed = tokenizer.encode_corpus(corpus)
print(corpus_transformed[:10])

encoded = tokenizer.encode(b"hello world")

print(tokenizer.decode(encoded))
