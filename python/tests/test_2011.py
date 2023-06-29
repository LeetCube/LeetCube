from python.src.code_2011 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["operations"]


def test():
    test = BoilerTest(2011, input_fetcher)
    solution = Solution().finalValueAfterOperations
    test.run_tests(solution)
