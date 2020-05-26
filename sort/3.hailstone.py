import numpy as np
import matplotlib.pyplot as plt

# Hailstone序列的非递归实现
def Hailstone(n):
    hailstone_list = []  # 记录序列
    while n > 1:
        hailstone_list.append(int(n))
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
    if n <= 1:
        hailstone_list.append(int(n))
    return hailstone_list, len(hailstone_list)

# Hailstone序列的递归实现
def recursive_hailstone(hailstone_list):
    """
    hailstone(n)序列求解，递归算法
    :param hailstone_list: 这里传入的是列表格式，比如[6]，计算列表末尾的Hailstone序列
    """
    n = hailstone_list[-1]
    if n <= 1:
        return 1
    if n % 2 == 0:
        hailstone_list.append(n // 2)
    else:
        hailstone_list.append(int(3 * n + 1))
    recursive_hailstone(hailstone_list)


# 只求Hailstone序列长度
def hailstone(n):
    length = 1
    while(1 < n):
        if n % 2 == 0:
            n = n/2
        else:
            n = n*3 + 1
        length += 1
    return length

# 获取Hailstone序列长度的部分大值
def test(n_size, floor):
    for i in range(n_size):
        res = hailstone(i)
        if res > floor:
            print(i, res)

# 实时绘制Hailstone序列长度图线
def plot(n_size):
    ax = []                    # 定义一个 x 轴的空列表用来接收动态的数据
    ay = []                    # 定义一个 y 轴的空列表用来接收动态的数据
    plt.ion()                  # 开启一个画图的窗口
    for i in range(n_size):       # 遍历所有值
        ax.append(i)               # 添加 i 到 x 轴的数据中
        ay.append(hailstone(i))    # 添加 i 的平方到 y 轴的数据中
        plt.clf()                  # 清除之前画的图
        plt.plot(ax, ay)            # 画出当前 ax 列表和 ay 列表中的值的图形
        plt.pause(0.1)             # 暂停一秒
    plt.ioff()                 # 关闭画图的窗口

# 实时绘制Hailstone序列长度点图
def hailstone_point(n):
    # x = [n for n in range(n)]
    # y = [hailstone(i) for i in x]
    x = []
    y = []
    for i in range(n):       
        x.append(i)               
        y.append(hailstone(i)) 
        plt.clf()
        plt.scatter(x, y)
        # plt.xticks(np.arange(min(x), max(x)+1, 1000))
        plt.pause(0.1) 

# 直接绘制点图 
def hailstone_pot(n):
    x = [n for n in range(1000000,n)]
    y = [hailstone(i) for i in x] 
    plt.plot(x, y)
    plt.xticks(np.arange(min(x), max(x)+1, 1000))
    plt.show()


if __name__ == '__main__':
    # f = open('hailstone.txt', 'a')
    # for i in range(2000):
    #     f.write(str(hailstone(i)) + '\n')
    hailstone_pot(1001105)



