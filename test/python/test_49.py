import sys
import os

sys.path.append(os.getcwd())
from .python_deps.boilerplate import BoilerTest
from src.python.code_49 import Solution

from typing import List


def input_fetcher(case):
    return case["input"]["strs"]


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


def test():
    test = BoilerTest(
        49, input_fetcher, output_comparator=nested_list_contents_comparator
    )
    solution = Solution().groupAnagrams
    test.run_tests(solution)
