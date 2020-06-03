# @Filename :   237.删除链表中的节点.py
# @Author :     Vistar
# @Language :   Python 3.7.7


class Solution:
    def deleteNode(self, node):
        """
        没有改变指针指向，只是用后一个节点覆盖了要删除的节点
        """
        # 使用node.next找到后一个节点
        node.val = node.next.val
        node.next = node.next.next