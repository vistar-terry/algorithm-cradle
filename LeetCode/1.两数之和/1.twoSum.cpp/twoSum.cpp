#include <iostream>
#include <vector>
#include <unordered_map>
#include <unistd.h>
using namespace std;

// 暴力查找
vector<int> twoSum(vector<int> &nums, int target)
{
    // cout << __func__ << ": " << endl;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

// 哈希查找
vector<int> twoSum1(vector<int> &nums, int target)
{
    // cout << __func__ << ": " << endl;
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end())
        {
            return {it->second, i};
        }
        hashtable[nums[i]] = i;
    }
    return {};
}

// 不支持返回值或输入为void的函数
template <typename T1, typename T2, typename... Args>
T1 doTime(const T2 &fun, Args &&...args)
{
    double dur;
    clock_t start, end;
    T1 res;
    start = clock();
    res = fun(std::forward<Args>(args)...);
    end = clock();
    dur = (double)(end - start);
    printf("Use Time: %f\n", (dur / CLOCKS_PER_SEC));
    return res;
}

void doTest(vector<int> (*fun)(vector<int> &, int), vector<vector<int>> test)
{
    double dur;
    clock_t start, end;
    for (int i = 0; i < test.size(); i++)
    {
        int itemSize = test[i].size();
        int target = test[i][itemSize - 3];
        vector<int> input;
        for (int j = 0; j < itemSize - 3; j++)
        {
            input.push_back(test[i][j]);
        }
        vector<int> expect = {test[i][itemSize - 2], test[i][itemSize - 1]};
        start = clock();
        vector<int> result = fun(input, target);
        end = clock();
        dur = (double)(end - start);
        printf("result: [%d, %d], expect: [%d, %d], useTime: %f ms\n",
               result[0], result[1], expect[0], expect[1], dur / CLOCKS_PER_SEC * 1000);
        expect.clear();
        input.clear();
        usleep(1000);
    }
}

int main()
{
    vector<vector<int>> test = {{2, 7, 11, 15, 9, 0, 1},
                                {4, 4, 8, 0, 1},                // 有重复*
                                {2, 7, 5, 8, 9, 0, 1},          // 前两位且相邻
                                {9, 2, 5, 7, 8, 10, 1, 4},      // 中间不相邻
                                {-1, -2, -3, -4, -5, -8, 2, 4}, // 负数
                                {3, 2, 4, 6, 1, 2},             // 有二倍数*
                                {-1, 5, -3, -4, -5, 0, 1, 4}};
    printf("twoSum: \n");
    doTest(twoSum, test);
    printf("twoSum1: \n");
    doTest(twoSum1, test);

    return 0;
}
