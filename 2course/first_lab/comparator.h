#pragma once

template <typename T>
static bool lessThan(const T &a, const T &b){
        return a < b;
    }

template <typename T>
static bool lessOrEquaThan(const T &a, const T &b){
        return a <= b;
    }

template <typename T>
static bool greaterThan(const T &a, const T &b){
        return a > b;
    }

template <typename T>
static bool greaterOrEqualThan(const T &a, const T &b){
        return a >= b;
    }