from python.src.code_1365 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["nums"]


def test():
    test = BoilerTest(1365, input_fetcher)
    solution = Solution().smallerNumbersThanCurrent
    test.run_tests(solution)
