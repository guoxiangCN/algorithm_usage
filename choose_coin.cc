// 1 3 5  11
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

// 贪心
int chooseCoin_Tanxin(std::vector<int> array, int target)
{
    std::sort(array.begin(), array.end(), std::greater<int>());
    int ret = 0;
    int total = 0;

    for (const int &e : array)
    {
        while (total + e <= target)
        {
            total += e;
            ret++;
        }
    }

    return ret;
}

// 分治 array pined with {1,3,5}
// 子问题会被重复求解.
int chooseCoin_forkjoin(std::vector<int> &array, int target)
{
    if (target == 1 || target == 3 || target == 5)
    {
        return 1;
    }
    else if (target == 2 || target == 4)
    {
        return 2;
    }
    else
    {
        int nLastChoose1 = chooseCoin_forkjoin(array, target - 1) + 1;
        int nLastChoose3 = chooseCoin_forkjoin(array, target - 3) + 1;
        int nLastChoose5 = chooseCoin_forkjoin(array, target - 5) + 1;
        return std::min({nLastChoose1, nLastChoose3, nLastChoose5});
    }
}

// 动态规划 with 递归
int chooseCoin_dp(std::vector<int> &array, int target, std::map<int, int> &bestCache)
{
    if (bestCache.find(target) != bestCache.end())
    {
        return bestCache[target];
    }
    
    if (target == 1 || target == 3 || target == 5)
    {
        bestCache[target] = 1;
        return 1;
    }
    else if (target == 2 || target == 4)
    {
        bestCache[target] = 2;
        return 2;
    }
    else
    {
        int nLastChoose1 = chooseCoin_dp(array, target - 1, bestCache) + 1;
        int nLastChoose3 = chooseCoin_dp(array, target - 3, bestCache) + 1;
        int nLastChoose5 = chooseCoin_dp(array, target - 5, bestCache) + 1;
        int min = std::min({nLastChoose1, nLastChoose3, nLastChoose5});
        bestCache[target] = min;
        return min;
    }
}

int chooseCoin_dp2(std::vector<int> array, int target, std::map<int, int> &bestCache)
{
    return 0;
}

int main(int argc, char **argv)
{
    std::vector<int> arr = {1, 3, 5};
    int target = 200;
    std::cout << chooseCoin_Tanxin(arr, target) << std::endl; // 3
    // std::cout << chooseCoin_forkjoin(arr, target) << std::endl; // 3 没有bestCache超级耗时

    std::map<int, int> bestCache;
    std::cout << chooseCoin_dp(arr, target, bestCache) << std::endl;
    return 0;
}