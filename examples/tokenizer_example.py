from tokkit import PyBytePairTokenizer, data_loader


# corpus = data_loader(
#     "/workspaces/tokkit/datasets/raw/combined.txt"
# )

tokenizer = PyBytePairTokenizer()

# tokenizer.fit(corpus, 10000, 10)

# corpus_transformed = tokenizer.encode_corpus(corpus)
# print(corpus_transformed[:10])

# encoded = tokenizer.encode("hello world !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~ ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþ")

encoded = [72, 101, 108, 108, 111, 203, 76, 232, 221, 4, 254, 188, 123, 162, 185, 48, 161, 86, 49, 162, 87, 249, 72, 215, 239, 193, 145, 54, 225, 89, 252, 95, 3, 146, 108, 213, 225, 132, 81, 228, 164, 4, 230, 118, 186, 225, 98, 127, 18, 254, 35, 64, 46, 195, 112, 77, 64, 249, 174, 207, 54, 254, 48, 251, 3]
print(tokenizer.decode(encoded))
