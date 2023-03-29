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

        Image<P, W, H>(const std::function<P(const size_t i, const size_t j)> & functor)
        {       
            for(size_t i = 0; i < W; ++i){
                for(size_t j = 0; j < H; ++j){
                   (*this)(i, j) = functor(i, j);
                }
            }
        }

    private:
    std::array<std::array<P, W>, H> _array;
};

template <typename A, size_t W, size_t H>
Image<A, W, H> operator+(const Image<A, W, H>& a, const Image<A, W, H>& b){
    Image<A, W, H> img = {};
    for(size_t i = 0; i < W; ++i){
        for(size_t j = 0; j < H; ++j){
            img(i, j) = a(i, j) + b(i, j);
        }
    }
    return img;
}

template<size_t W, size_t H>
Image<RGB, W, H> operator+(const Image<Luma, W, H> & a,
          const Image<RGBA, W, H> & b)
{
    Image<RGB, W, H> img = {};
    for(size_t i = 0; i < W; ++i){
        for(size_t j = 0; j < H; ++j){
            img(i, j) = a(i, j) + b(i, j);
        }
    }
    return img;
}

template<size_t W, size_t H>
Image<RGB, W, H> operator+(const Image<Luma, W, H> & a,
          const Image<RGB , W, H> & b)
{
    Image<RGB, W, H> img = {};
    for(size_t i = 0; i < W; ++i){
        for(size_t j = 0; j < H; ++j){
            img(i, j) = a(i, j) + b(i, j);
        }
    }
    return img;
}