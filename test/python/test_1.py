import sys
import os

sys.path.append(os.getcwd())
from .python_deps.boilerplate import Test
from src.python.code_1 import Solution


def input_fetcher(case):
    return case["input"]["nums"], case["input"]["target"]


def test():
    test = Test(1, input_fetcher)
    solution = Solution().twoSum
    test.run_tests(solution)
