#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA {
    uint8_t r, g, b, a;
};

struct RGB {
    uint8_t r, g, b;
};

struct Luma {
    uint8_t gray;
};

template<typename A, typename B>
A from(const B & stuff);

template<typename A>
A from(const A & x)
{
    return x;
};

template<>
RGB from(const RGBA & x)
{
    return {x.r, x.g, x.b};
};

template<>
RGBA from(const RGB & x)
{
    return {x.r, x.g, x.b, 255};
};

template<>
Luma from(const RGB & x)
{
    return {lib::rgb_to_grayscale(x.r, x.g, x.b)};
};

template<>
RGB from(const Luma & x)
{
    const auto [r, g, b] = lib::grayscale_to_rgb(x.gray);
    return {r, g, b};
};

template<>
Luma from(const RGBA & x)
{
    return from<Luma, RGB>(from<RGB, RGBA>(x));
};

template<>
RGBA from(const Luma & x)
{
    return from<RGBA, RGB>(from<RGB, Luma>(x));
};

RGBA operator+(const RGBA & lhs, const RGBA & rhs)
{
    const auto [r, g, b, a] = lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a,
                                             rhs.r, rhs.g, rhs.b, rhs.a);
    return {r, g, b, a};
};

#define IMPL_ADD(A, B, C)                                       \
C operator+(const A& a, const B& b)                             \
{                                                               \
    return from<C, RGBA>(from<RGBA, A>(a) + from<RGBA, B>(b));  \
}

IMPL_ADD(RGBA, RGB , RGBA);
IMPL_ADD(RGB , RGBA, RGB );
IMPL_ADD(Luma, RGBA, RGB );
IMPL_ADD(Luma, RGB , RGB );
IMPL_ADD(RGB , RGB , RGB );