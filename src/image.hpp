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
            for(size_t i = 0; i < W; ++i){
                for(size_t j = 0; j < H; ++j){
                    _array[i][j] = pixel;
                }
            }
        }

        const P& operator()(size_t i, size_t j) const {
            return _array[j][i];
        }

        P& operator()(size_t i, size_t j) {
            return _array[j][i];
        }

    private:
    std::array<std::array<P, W>, H> _array;
};