#pragma once

#include <vector>
#include <assert.h>


// 01背包问题  回溯算法
// 重量weight  w1, w2, w3, w4 ...
// 价值value   v1, v2, v3, v4 ...
// 怎么装价值最大化

std::vector<int> saveToBag(const std::vector<int> &weights, const std::vector<int> &values, int bagCapacity)
{
     assert(weights.size() == values.size());

     
}

int main(int argc, char **argv)
{
    std::vector<int> weights = {1, 2,  5,  8, 9,6};
    std::vector<int> values  = {9, 11, 4,  7, 3, 1};
    assert(weights.size() == values.size());



    int bagCapacity = 100;



    return 0;
}