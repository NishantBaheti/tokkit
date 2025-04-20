rm ./run.so
g++ -std=c++17 -Wall -O2 \
    ./src/tokkit/cpp/data.cpp \
    ./src/tokkit/cpp/tokenizer.cpp \
    ./src/tokkit/cpp/run.cpp \
    ./src/tokkit/cpp/utils.cpp \
    -o ./run.so
./run.so
rm ./run.so