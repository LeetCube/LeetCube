import sys
import os

sys.path.append(os.getcwd())
from .python_deps.boilerplate import BoilerTest
from src.python.code_1 import Solution


def input_fetcher(case):
    return case["input"]["nums"], case["input"]["target"]


def test():
    test = BoilerTest(1, input_fetcher)
    solution = Solution().twoSum
    test.run_tests(solution)
