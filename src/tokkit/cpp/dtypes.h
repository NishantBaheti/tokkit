#include <unordered_map>
#include <array>
#include <functional>
#pragma once

using namespace std;

template<typename T, std::size_t N>

struct ArrayHasher {
    std::size_t operator()(const std::array<T, N>& arr) const {
        std::size_t hash = 0;
        for (const auto& val : arr) {
            hash ^= std::hash<T>{}(val)+ 0x9e3779b9 + (hash << 6) + (hash >> 2); // boost-style hash combine
        }
        return hash;
    }
};
using DTYPE_BYTEPAIR = std::array<int, 2>;
using DTYPE_CHARPAIR = std::array<char, 2>;
using DTYPE_BYTEPAIR_VOCAB = std::unordered_map<DTYPE_BYTEPAIR, int, ArrayHasher<int, 2>>;
using DTYPE_BYTEPAIR_REV_VOCAB = std::unordered_map<int, DTYPE_BYTEPAIR>;
using DTYPE_BYTEPAIR_STATS = std::unordered_map<DTYPE_BYTEPAIR, int, ArrayHasher<int, 2>>;
