# @Filename :   insert.py
# @Author :     Vistar
# @Language :   Python 3.7.7


# 调用list的函数
l = [1, 2, 3, 4, 5]
print(l.insert(12, 10))


# 利用list的特性
def insert(my_list, i, e):
    return my_list[:i] + [e] + my_list[i:]

print(insert([1, 2, 3, 4, 5], 2, 10))
print(insert([1, 2, 3, 4, 5], -2, 10))
print(insert([1, 2, 3, 4, 5], 10, 10))


# 使用原始数组的方法
pass

