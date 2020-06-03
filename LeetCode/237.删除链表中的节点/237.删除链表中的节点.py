# @Filename :   237.删除链表中的节点.py
# @Author :     Vistar
# @Language :   Python 3.7.7


class Solution:
    def deleteNode(self, node):
        """
        用后一个节点覆盖了要删除的节点
        在链表占用的存储空间上，实际删除的空间是要删除节点的下一个节点的空间
        """
        # 使用node.next找到后一个节点
        # 用后一个节点的值覆盖要删除的节点值
        node.val = node.next.val
        # 用后一个节点的指针覆盖要删除的节点指针
        node.next = node.next.next