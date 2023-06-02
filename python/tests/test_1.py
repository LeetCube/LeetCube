from python.src.code_1 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["nums"], case["input"]["target"]


def test():
    test = BoilerTest(1, input_fetcher)
    solution = Solution().twoSum
    test.run_tests(solution)
