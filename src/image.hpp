#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>

template <typename P, size_t W, size_t H>
class Image {
    public:
        Image<P, W, H>() = default;

        Image<P, W, H>(const P& pixel)
        {
            for(int i = 0; i < W; ++i){
                for(int j = 0; j < H; ++j){
                    _array[i][j] = pixel;
                }
            }
        }
    private:
    std::array<std::array<P, W>, H> _array;
};