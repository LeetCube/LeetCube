import sys
import os

sys.path.append(os.getcwd())
from .python_deps.boilerplate import Test
from src.python.code_934 import Solution


def input_fetcher(case):
    return case["input"]["grid"]


def test():
    test = Test(934, input_fetcher)
    solution = Solution().shortestBridge
    test.run_tests(solution)
