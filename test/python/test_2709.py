import sys
import os
sys.path.append(os.getcwd())
from .BaseTest import BaseTest
from src.python.code_2709 import Solution


def input_fetcher(case):
    return case["input"]["nums"]


if __name__ == "__main__":
    test = BaseTest(2709, input_fetcher)
    solution = Solution().canTraverseAllPairs
    test.run_tests(solution)
