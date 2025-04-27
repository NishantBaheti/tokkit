from tokkit import PyBytePairTokenizer, data_loader


corpus = data_loader(
    "/workspaces/tokkit/datasets/raw/combined.txt"
)

tokenizer = PyBytePairTokenizer()

tokenizer.fit(corpus, 10000, 10)

corpus_transformed = tokenizer.encode_corpus(corpus)
print(corpus_transformed[:10])

encoded = tokenizer.encode("hello world !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~ ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþ")

print(tokenizer.decode(encoded))
