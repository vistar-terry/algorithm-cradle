import timeit

def twoSum0(nums, target):
    for i in range(len(nums)):
        for j in range(i+1,len(nums)):
            if nums[i] + nums[j] == target:
                return [i,j]

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

# # 测试输出是否正确
# # 后两位为预期结果，倒数第三位为 target，其余为输入数组
# test = [[4,4,8,0,1],    # 有重复*
#         [2,7,5,8,9,0,1],    # 前两位且相邻
#         [9,2,5,7,8,10,1,4], # 中间不相邻
#         [-1,-2,-3,-4,-5,-8,2,4],    # 负数
#         [3,2,4,6,1,2],      # 有二倍数*
#         [-1,5,-3,-4,-5,0,1,4]]
# for i in range(len(test)):
#     print("输出：{0}，预期：{1}".format(twoSum1(test[i][:-3],test[i][-3]),test[i][-2:]))

# 测试执行时间
def dotime(f_names, f_input, do_number):
    times = []
    for f_name in f_names:
        times.append(timeit.timeit(f_name + "(" + f_input + ")", "from __main__ import " + f_name, number=do_number))
    return times

f_names = ["twoSum0","twoSum", "twoSum1"]
f_input = "[2,11,15,11,11,15,55,89,11,15,55,89,11,15,55,89,7], 9"
do_number = 10000000
print(dotime(f_names, f_input, do_number))
