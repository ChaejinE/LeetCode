from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        dummyA = ListNode()  # less than nodes
        dummyB = ListNode()  # greater than equal nodes

        crnt_node = head
        less_than_node = dummyA
        greater_than_equal_node = dummyB
        while crnt_node:
            if crnt_node.val < x:
                less_than_node.next = crnt_node
                less_than_node = less_than_node.next
            else:
                greater_than_equal_node.next = crnt_node
                greater_than_equal_node = greater_than_equal_node.next

            crnt_node = crnt_node.next

        if greater_than_equal_node:
            greater_than_equal_node.next = None

        less_than_node.next = dummyB.next
        dummyB.next = None
        return dummyA.next
