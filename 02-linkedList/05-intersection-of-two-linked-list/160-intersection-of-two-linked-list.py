from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(
        self, headA: ListNode, headB: ListNode
    ) -> Optional[ListNode]:
        if headA is None or headB is None:
            return None

        # 교차점이 없는 경우, 2번째 cycle에서 difference가 0이되도록 한 것이므로 None에서 만난다.
        nodeA, nodeB = headA, headB
        while nodeA is not nodeB:
            nodeA = nodeA.next if nodeA is not None else headB
            nodeB = nodeB.next if nodeB is not None else headA

        return nodeA
