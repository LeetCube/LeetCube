from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        carry = 0
        res = ListNode(-1)
        head = res
        while l1 is not None or l2 is not None:
            curr1 = l1.val if l1 else 0
            curr2 = l2.val if l2 else 0
            sum = curr1 + curr2 + carry
            if sum >= 10:
                carry = 1
                sum -= 10
            else:
                carry = 0
            res.next = ListNode(sum)
            res = res.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        if carry:
            res.next = ListNode(1)

        return head.next
