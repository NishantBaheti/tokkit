rm ./run.so
g++-13 -std=c++23 -Wall -O2 \
    ./src/tokkit/cpp/data.cpp \
    ./src/tokkit/cpp/tokenizer.cpp \
    ./src/tokkit/cpp/run.cpp \
    -o ./run.so
./run.so
rm ./run.so