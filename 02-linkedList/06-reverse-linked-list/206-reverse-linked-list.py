from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev_node, cur_node, next_node = None, None, None
        if head is not None:
            prev_node = head
        else:
            return head

        if head.next is not None:
            cur_node = head.next
            if head.next.next is not None:
                next_node = head.next.next

        while cur_node or next_node:
            cur_node.next = prev_node
            prev_node = cur_node
            cur_node = next_node
            next_node = next_node.next if next_node else None

        head.next = None
        return prev_node
