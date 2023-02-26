from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        carry = 0
        dummy = ListNode()
        crnt = dummy
        while l1 and l2:
            a, b = l1.val, l2.val
            summation = a + b + carry
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

            crnt.next = ListNode(val)
            crnt = crnt.next

        crnt.next = ListNode(carry) if carry else None
        return dummy.next
