# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        prev, crnt = dummy, head
        while crnt:
            if crnt.val == val:
                prev.next = crnt.next
            else:
                prev = crnt

            crnt = crnt.next

        return dummy.next
