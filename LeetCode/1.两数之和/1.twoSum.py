from dotest import dotest
import sys
sys.path.append('..')

# 暴力查找
def twoSum0(nums, target):
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]


# 哈希表查找
def twoSum(nums, target):
    for index, num in enumerate(nums):
        another_num = target - num
        nums[index] = None
        if another_num in nums:
            return [index, nums.index(another_num)]
    return None


def twoSum1(nums, target):
    hashmap = {}
    for index, num in enumerate(nums):
        another_num = target - num
        if another_num in hashmap:
            return [hashmap[another_num], index]
        else:
            hashmap[num] = index
    return None


if __name__ == "__main__":
    f_names = [twoSum0, twoSum, twoSum1]
    # 后两位为预期结果，倒数第三位为 target，其余为输入数组
    test = [[4, 4, 8, 0, 1],            # 有重复*
            [2, 7, 5, 8, 9, 0, 1],      # 前两位且相邻
            [9, 2, 5, 7, 8, 10, 1, 4],  # 中间不相邻
            [-1, -2, -3, -4, -5, -8, 2, 4],    # 负数
            [3, 2, 4, 6, 1, 2],      # 有二倍数*
            [-1, 5, -3, -4, -5, 0, 1, 4]]
    dotest.check(f_names, test)
    f_input = "[2,11,15,11,11,15,55,89,11,15,55,89,11,15,55,89,7], 9"
    do_number = 1_000_000
    print("执行%d次用时: " % do_number)
    print(dotest.dotime(f_names, f_input, do_number))
