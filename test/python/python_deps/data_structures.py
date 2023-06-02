from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def build_linked_list(input: List) -> Optional[ListNode]:
    if len(input) == 0:
        return None
    head = ListNode(input[0])
    curr = head
    for i in input[1:]:
        curr.next = ListNode(i)
        curr = curr.next
    return head


def listnode_to_list(ln: ListNode):
    acc = []
    while ln:
        acc.append(ln.val)
        ln = ln.next

    return acc
