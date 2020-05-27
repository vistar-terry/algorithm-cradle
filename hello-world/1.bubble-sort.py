# @Filename : bubble_sort.py
# @Author :   Vistar
# @Language : Python 3.7.7

# 参考：
# https://stackabuse.com/bubble-sort-in-python/
# https://t.zsxq.com/nEU3VJ6

# 冒泡排序原理：不断比较两个相邻的元素，将较大的元素交换到右边（升序）

# 过程：
# 1. 比较第1个数和第2个数，较大的放在右边
# 2. 比较第2个数和第3个数，较大的放在右边
# ...
# n-1. 直到最后两个数比较完，整个数列的最大值已位于最右边
# (最大值就像水中的气泡一样，一直升到最右边)
# 一直重复上述步骤，把未排序数列中的最大值放到右边，最终整个数列排序完成

import timeit

def bubble_sort(our_list):
    # We go through the list as many times as there are elements
    for i in range(len(our_list)):
        # We want the last pair of adjacent elements to be (n-2, n-1)
        for j in range(len(our_list) - 1):
            if our_list[j] > our_list[j+1]:
                # Swap
                our_list[j], our_list[j+1] = our_list[j+1], our_list[j]
    return our_list

# 优化一：# 保存到变量，减少函数调用次数，排序执行很大次数时，效率明显提高
def bubble_sort1(our_list):
    lenght = len(our_list) 
    # 批次循环，有多少个数，循环多少次
    for i in range(lenght):
        # 一个批次内的循环，目的是将未排序数列的最大值移到最右边
        for j in range(lenght - 1): 
            if our_list[j] > our_list[j+1]: # 比较相邻两个数
                # 交换
                our_list[j], our_list[j+1] = our_list[j+1], our_list[j]
    return our_list

# 优化二：添加有序标记（has_swapped），当没有元素交换时跳出循环
# 原方法，当没有元素交换时，仍要遍历剩余元素
# 对于混乱度小的数列，此方法优势明显
def bubble_sort_check_swapped(our_list):
    # We want to stop passing through the list
    # as soon as we pass through without swapping any elements
    has_swapped = True
    while(has_swapped):
        has_swapped = False
        for i in range(len(our_list) - 1):
            if our_list[i] > our_list[i+1]:
                # Swap
                our_list[i], our_list[i+1] = our_list[i+1], our_list[i]
                has_swapped = True
    return our_list

# 优化三：记录有序/无序边界，已有序的元素不需要再进行操作，因此每轮比较的数列长度会减小
def bubble_sort_ignore_done(our_list):
    # With each consecutive iteration
    # we can look at one less element than before.
    # More precisely, in the k-th iteration,
    # only need to look at the first n - k + 1 elements.
    has_swapped = True
    num_of_iterations = 0
    while(has_swapped):
        has_swapped = False
        for i in range(len(our_list) - num_of_iterations - 1):
            if our_list[i] > our_list[i+1]:
                # Swap
                our_list[i], our_list[i+1] = our_list[i+1], our_list[i]
                has_swapped = True
        num_of_iterations += 1
    return our_list


# our_list = [19, 13, 6, 9, 9, 19, 25, 18, 8]
# our_list = [1,2,3,4,5,6,7,8]
# print("unsort list:", our_list)
# print("sorted list:", bubble_sort_check_swapped(our_list))

loop_number = 1000000
print("bubble_sort:", timeit.timeit("bubble_sort([1,2,3,4,5,6,7,8])", "from __main__ import bubble_sort", number=loop_number))
print("bubble_sort1:", timeit.timeit("bubble_sort1([1,2,3,4,5,6,7,8])", "from __main__ import bubble_sort1", number=loop_number))
print("bubble_sort_check_swapped: ", timeit.timeit("bubble_sort_check_swapped([1,2,3,4,5,6,7,8])", "from __main__ import bubble_sort_check_swapped", number=loop_number))
print("bubble_sort_ignore_done: ", timeit.timeit("bubble_sort_ignore_done([1,2,3,4,5,6,7,8])", "from __main__ import bubble_sort_ignore_done", number=loop_number))
