# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        list_head, value = ListNode(0), 0
        node = list_head
        while l1 or l2:
            if l1:
                value += l1.val
                l1 = l1.next
            if l2:
                value += l2.val
                l2 = l2.next
            node.next = ListNode(value % 10)
            node = node.next
            value //= 10
        if value:
            node.next = ListNode(value)
        return list_head.next