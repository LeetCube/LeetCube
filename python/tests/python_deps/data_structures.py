from typing import Optional
from typing import List


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


def nested_list_contents_comparator(
    answer: List[List[str]], actual: List[List[str]]
) -> bool:
    if len(answer) != len(actual):
        return False

    answer.sort()
    actual.sort()

    for ans, act in zip(answer, actual):
        if ans.sort() != act.sort():
            return False

    return True


# Standard definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# creation of a binary tree: deserializes JSON list input into binary tree of type TreeNode.
def createBinaryTree(data, index=0):
    parentNode = None
    if index < len(data):
        if data[index] == None:
            return
        parentNode = TreeNode(data[index])  # initialize tree node object

        # left child of a node exists at 2*(index)
        leftChildIndex = 2 * index

        # right child of a node exists at 2*(index)
        rightChildIndex = 2 * index + 1

        # we obtained left and right child indices. Now, we increment by 1 to set up recursion
        parentNode.left = createBinaryTree(
            data, leftChildIndex + 1
        )  # indices 1, 3, 7, 15, ... within JSON list
        parentNode.right = createBinaryTree(
            data, rightChildIndex + 1
        )  # indices 2, 5, 12, 25, ... within JSON list
    return parentNode
