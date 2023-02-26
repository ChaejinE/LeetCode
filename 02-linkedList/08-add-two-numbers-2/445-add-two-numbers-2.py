from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    @staticmethod
    def reverse(list_node: Optional[ListNode]) -> Optional[ListNode]:
        if not list_node:
            return list_node

        prev_node, crnt_node, next_node = list_node, None, None
        if list_node.next:
            crnt_node = list_node.next
            if list_node.next.next:
                next_node = list_node.next.next

        while crnt_node or next_node:
            crnt_node.next = prev_node
            prev_node = crnt_node
            crnt_node = next_node
            next_node = next_node.next if next_node else None

        list_node.next = None
        return prev_node

    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)

        carry = 0
        dummy = ListNode()
        output = dummy
        while l1 and l2:
            summation = l1.val + l2.val + carry
            carry, val = summation // 10, summation % 10

            if l1.next and not l2.next:
                l1 = l1.next
                l2 = ListNode()
            elif not l1.next and l2.next:
                l1 = ListNode()
                l2 = l2.next
            else:
                l1 = l1.next
                l2 = l2.next

            output.next = ListNode(val)
            output = output.next

        if carry:
            output.next = ListNode(carry)
        output = self.reverse(dummy.next)
        return output
