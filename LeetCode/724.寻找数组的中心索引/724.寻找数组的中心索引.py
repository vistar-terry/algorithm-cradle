# @Filename :   724.寻找数组的中心索引.py
# @Author :     Vistar
# @Language :   Python 3.7.7


# 题目
# 给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
# 我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
# 如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。

import timeit

# 第一次的代码
# 执行用时：3420 ms
# 内存消耗：14.7 MB
def pivotIndex(nums):
    total = sum(nums) / 2
    for i in range(len(nums)):
        if sum(nums[:i])+(nums[i]/2) == total:
            return i
    return -1

# 评论区代码
# 执行用时：72 ms
# 内存消耗：14.7 MB
def pivo(nums):
    total = sum(nums)
    part_sum = 0
    for i, j in enumerate(nums):
        if part_sum == (total - j) / 2:
            return i
        part_sum += j
    return -1

# 参考改进
# 执行用时：56 ms
# 内存消耗：14.7 MB
def pivotIndex_better(nums):
    total = sum(nums)
    left_sum = 0
    for i, j in enumerate(nums):
        if 2*left_sum+j == total:
            return i
        left_sum += j
    return -1


# 测试
# print(pivotIndex1([-1,-1,-1,0,1,1]))
# print("pivotIndex:", timeit.timeit(
#     "pivotIndex([1,7,3,6,5,6])", "from __main__ import pivotIndex", number=1000000))
print("pivo:", timeit.timeit(
    "pivo([1,7,3,6,5,6])", "from __main__ import pivo", number=1000000))
print("pivotIndex_better:", timeit.timeit(
    "pivotIndex_better([1,7,3,6,5,6])", "from __main__ import pivotIndex_better", number=1000000))
