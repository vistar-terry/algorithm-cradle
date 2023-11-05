import timeit

# 测试输出是否正确
def check(f_names, test):
    for f_name in f_names:
        print("测试函数 %s" % f_name.__name__)
        for i in range(len(test)):
            print("输出：{0}，预期：{1}".format(
                f_name(test[i][:-3], test[i][-3]), test[i][-2:]))
        print("")


# 测试执行时间
def dotime(f_names, f_input, do_number):
    times = []
    for f_name in f_names:
        times.append(timeit.timeit(f_name.__name__ + "(" + f_input + ")",
                                   "from __main__ import " + f_name.__name__,
                                   number=do_number))
    return times