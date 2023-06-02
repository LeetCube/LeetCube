import sys
import os

sys.path.append(os.getcwd())
from .python_deps.boilerplate import BoilerTest
from src.python.code_12 import Solution


def input_fetcher(case):
    return case["input"]["num"]


def test():
    test = BoilerTest(12, input_fetcher)
    solution = Solution().intToRoman
    test.run_tests(solution)
