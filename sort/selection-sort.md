### 选择排序

选择排序思想：不断选择最小值放到最前面（升序）

选择排序思路：

1.  指针先指向第一个数

2.  用第一个数与后面的数比较，如果第一个数小，指针不动，如果后面的数小，指针指向后面那个数

3.  重复2的操作，直到把所有数遍历一遍找出了最小值，将最小值与第一个数交换位置

4.  在未排序数列中重复2、3的操作

```python
# 选择排序思想：不断选择最小值放到最前面（升序）
# 1. 指针先指向第一个数
# 2. 用第一个数与后面的数比较，如果第一个数小，指针不动，如果后面的数小，指针指向后面那个数
# 3. 重复2的操作，直到把所有数遍历一遍找出了最小值，将最小值与第一个数交换位置
# 4. 在未排序数列中重复2、3的操作

import timeit


def selection_sort(our_list):
    length = len(our_list)
    for i in range(length - 1):
        min = i
        for j in range(i + 1, length):
            if our_list[j] < our_list[min]:
                min = j
        if min != i:
            our_list[min], our_list[i] = our_list[i], our_list[min]
    return our_list


# 有如下优化，但效率却低于未优化
def selection_sort2(x):
    i = 0
    '''
    1、最小值更新的位置是：i
    2、最大值更新的位置是：len(list)-1-i
    3、整个list的索引的值最大是len(list)-1;因为索引从0开始
    '''
    while i <= len(x) // 2:
        minindex = i
        maxindex = i
        j = i + 1
        # 遍历后续位置，更新最大值和最小值的位置
        while j < len(x)-i:
            if x[minindex] > x[j]:
                minindex = j
            if x[maxindex] < x[j]:
                maxindex = j
            j += 1
        # 如果最小值与最大值相同，说明剩下的数字都相同，可以直接结束
        if x[minindex] == x[maxindex]:
            return x
        # 如果最小值的索引位置不是初始位置，则更新最小值到初始的位置
        if minindex != i:
            x[i], x[minindex] = x[minindex], x[i]
        # 最大值和最小值的索引位置成对出现，
        # 如果最大值的索引位置不是总的索引值减去最小值的索引，则更新最大值到对应的索引位置
        if maxindex != len(x)-1-i:
            # 如果初始索引的位置就是最大值时，先交换minindex和i之后，最大值的下标变成了minindex
            if maxindex != i:
                x[len(x)-1-i], x[maxindex] = x[maxindex], x[len(x)-1-i]
            # 应该交换minindex和n-i-1，而不是maxindex和n-i-1
            else:
                x[len(x)-1-i], x[minindex] = x[minindex], x[len(x)-1-i]
        i += 1
    return x


if __name__ == "__main__":
    our_list = [12, 4, 15, 7, 8, 26, 16, 25, 8, 85]
    # print("unsort list:", our_list)
    # print("sorted list:", selection_sort2(our_list))
    print("selection_sort:", timeit.timeit(
        "selection_sort([12,4,15,7,8,26,16,25,8,85])", "from __main__ import selection_sort", number=10000))
    print("selection_sort2:", timeit.timeit(
        "selection_sort2([12,4,15,7,8,26,16,25,8,85])", "from __main__ import selection_sort2", number=10000))
```



