import sys
import os

sys.path.append(os.getcwd())
from .python_deps.boilerplate import BoilerTest
from src.python.code_2709 import Solution


def input_fetcher(case):
    return case["input"]["nums"]


def test():
    test = BoilerTest(2709, input_fetcher)
    solution = Solution().canTraverseAllPairs
    test.run_tests(solution)
