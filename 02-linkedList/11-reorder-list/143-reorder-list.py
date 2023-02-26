from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    @staticmethod
    def search_middle(list_node: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast = list_node, list_node

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        return slow

    @staticmethod
    def reverse(list_node: Optional[ListNode]) -> None:
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

    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head.next is None:
            return

        middle_node = self.search_middle(head)
        reversed_node = self.reverse(middle_node.next)
        middle_node.next = None
        crnt_node = head
        while crnt_node and reversed_node:
            next_node, next_reversed_node = crnt_node.next, reversed_node.next
            reversed_node.next = crnt_node.next
            crnt_node.next = reversed_node
            crnt_node = next_node
            reversed_node = next_reversed_node
