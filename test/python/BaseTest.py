import json
from timeit import default_timer as timer
from typing import Union, List, Optional

from Structure import ListNode


def default_output_fetcher(case):
    return case["output"]


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


class BaseTest:
    def __init__(
        self,
        number: Union[int, str],
        input_fetcher,
        output_fetcher=default_output_fetcher,
        output_transformer=None,
    ):
        with open(f"../test_json/test_{number}.json", "r") as f:
            self.data = json.load(f)
            self.input_fetcher = input_fetcher
            self.output_fetcher = output_fetcher
            self.output_transformer = output_transformer

    def run_tests(self, solution):
        start = timer()
        for case in self.data:
            input = self.input_fetcher(case)
            answer = self.output_fetcher(case)
            if isinstance(input, tuple):
                actual = solution(*input)
            else:
                actual = solution(input)
            if self.output_transformer is not None:
                actual = self.output_transformer(actual)
            assert (
                actual == answer
            ), f"Failed case. Should have been {answer}, was {actual}\n: {input}"

        end = timer()
        print(f"{len(self.data)} cases ran in{(end - start) * 1000: .0f} ms")
