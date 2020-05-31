# @Filename :   selection_sort.py
# @Author :     Vistar
# @Language :   Python 3.7.7

# 选择排序思想：不断选择最小值放到最前面（升序）

# 选择排序思路：
# 1. 指针先指向第一个数
# 2. 用第一个数与后面的数比较，如果第一个数小，指针不动，如果后面的数小，指针指向后面那个数
# 3. 重复2的操作，直到把所有数遍历一遍找出了最小值
# 4. 将最小值与第一个数交换位置
# 5. 在未排序数列中重复2、3、4的操作
#
# 算法分析：
# 时间复杂度：O(n2)
# 空间复杂度：O(1)
# 最好和最坏的时间复杂度都为 O(n2)
# 不稳定性：当比较的两项相等，可能仍会交换，改变原有的相对位置。

import timeit

# 原有思路实现
def selection_sort(our_list):
    length = len(our_list)
    for i in range(length - 1):
        # 1. 指针先指向第一个数
        min = i
        # 2. 用第一个数与后面的数比较，如果第一个数小，指针不动，如果后面的数小，指针指向后面那个数
        # 3. 重复2的操作，直到把所有数遍历一遍找出了最小值
        for j in range(i + 1, length):
            if our_list[j] < our_list[min]:
                min = j
        # 4. 将最小值与第一个数交换位置
        our_list[min], our_list[i] = our_list[i], our_list[min]
    return our_list


# 验证不稳定性
def selection_sort_test(our_list):
    length = len(our_list)
    for i in range(length - 1):
        min = i
        for j in range(i + 1, length):
            if our_list[j][1] < our_list[min][1]:  # 比较元组的第二个元素
                min = j
        our_list[min], our_list[i] = our_list[i], our_list[min]
    return our_list


# 效率优化，找到最小和最大值，分别放在两端
def selection_sort_better(our_list):
    n = len(our_list)
    for i in range(n//2):
        min_mark = i
        max_mark = n-i-1
        for j in range(i+1, n-i):
            if our_list[j] < our_list[min_mark]:
                min_mark = j
        if min_mark != i:
            our_list[i], our_list[min_mark] = our_list[min_mark], our_list[i]

        for j in range(n-i-2, i, -1):
            if our_list[j] > our_list[max_mark]:
                max_mark = j
        if max_mark != n-i-1:
            our_list[n-i-1], our_list[max_mark] = our_list[max_mark], our_list[n-i-1]
    return our_list
            

if __name__ == "__main__":
    # 原有思路测试
    # our_list = [12, 4, 15, 7, 8, 26, 16, 25, 8, 85]
    # 验证不稳定性
    # our_list = [(1, 4), (2, 4), (3, 2), (4, 5)]

    # print("unsort list:", our_list)
    # print("sorted list:", selection_sort_test(our_list))

    # 验证效率优化
    print("selection_sort:", timeit.timeit(
        "selection_sort([12,4,15,7,8,26,16,25,8,85])", "from __main__ import selection_sort", number=1000000))
    print("selection_sort_better:", timeit.timeit(
        "selection_sort_better([12,4,15,7,8,26,16,25,8,85])", "from __main__ import selection_sort_better", number=1000000))

