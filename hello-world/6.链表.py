# 定义单链表节点
class ListNode(object):
    def __init__(self, x=None):
        self.val = x
        self.next = None

# 单链表类
class SingleLinkedList(object):
    def __init__(self):
        self._head = ListNode()

    def is_empty(self):
        # 判空
        return self._head.next == None

    def size(self):
        # 长度
        # 指向头结点下一个， 即第一个节点
        cur = self._head.next
        count = 0
        while cur != None:
            count += 1
            cur = cur.next
        return count

    def print_all(self):
        # 打印
        cur = self._head.next
        while cur != None:
            print(cur.val)
            cur = cur.next
            print(" ")

    def add(self, value):
        # 头插
        node = ListNode(value)
        node.next = self._head.next
        self._head.next = node

    def append(self, value):
        # 尾插
        if self.is_empty():
            self.add(value)
        else:
            node = ListNode(value)
            cur = self._head
            while cur.next != None:
                cur = cur.next
            cur.next = node

    def insert(self, pos, value):
        # 指定位置插入
        if pos <= 0:
            self.add(value)
        elif pos > self.size()-1:
            self.append(value)
        else:
            node = ListNode(value)
            count = 0
            cur = self._head
            while count < pos-1:
                cur = cur.next
                count += 1
            node.next = cur.next
            cur.next = node

    def get_index(self, index):
        # 获取index 下标位置元素
        if self.size() > index >= 0:
            cur = self._head.next
            pos = 0
            while pos < index:
                cur = cur.next
                pos += 1
            return cur.val
        else:
            return 'index error'

    def delete_index(self, index):
        if self.size() > index > 0:
            cur = self._head.next
            pos = 0
            while pos < index-1:
                cur = cur.next
                pos += 1
            cur.next = cur.next.next
        else:
            return 'index error'

    def search(self, value):
        """链表查找节点是否存在，并返回True或者False"""
        cur = self._head
        while cur != None:
            if cur.val == value:
                return True
            cur = cur.next
        return False


class Solution:
    def getiNode(self, _head, n, i):
        '''
        :param _head: 链表头节点
        :param n: 链表长度
        :param i: 返回的第i个结点
        :return:
        '''
        if i < 0 or i > n:
            raise IndexError
        cur = _head
        for _ in range(i):
            cur = cur.next
        return cur.val


if __name__ == '__main__':
    lst = [2, 5, 7, 9, 1, 4, 6]
    n = len(lst)
    i = 2
    # 生成链表
    _head = ListNode(None)
    tmp = _head
    for v in lst:
        newNode = ListNode(v)
        tmp.next = newNode
        tmp = newNode

    _head = _head.next

    # 访问
    so = Solution()
    innode = so.getiNode(_head, n, i)
    print('链表为：', lst, '访问索引：', i, '节点值：', innode)
