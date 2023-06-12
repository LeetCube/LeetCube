from python.src.code_2734 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["s"]


def test():
    test = BoilerTest(2734, input_fetcher)
    solution = Solution().smallestString
    test.run_tests(solution)
