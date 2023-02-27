from typing import Optional


# Definition for a Node.
class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        dummy = Node(0)
        origin_crnt_node = head
        while origin_crnt_node:
            origin_next_node = origin_crnt_node.next
            new_node = Node(x=origin_crnt_node.val, next=origin_crnt_node.next)

            origin_crnt_node.next = new_node
            origin_crnt_node = origin_next_node

        origin_crnt_node = head
        copy_node = dummy
        copy_node.next = origin_crnt_node.next if origin_crnt_node else None
        copy_node = copy_node.next
        while origin_crnt_node:
            copy_node.random = (
                origin_crnt_node.random.next if origin_crnt_node.random else None
            )

            copy_node = copy_node.next.next if copy_node.next else None
            origin_crnt_node = origin_crnt_node.next.next

        origin_crnt_node = head
        copy_node = dummy.next
        while origin_crnt_node:
            origin_crnt_node.next = copy_node.next
            copy_node.next = copy_node.next.next if copy_node.next else None

            origin_crnt_node = origin_crnt_node.next
            copy_node = copy_node.next

        return dummy.next
