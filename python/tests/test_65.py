from python.src.code_65 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["s"]


def test():
    test = BoilerTest(65, input_fetcher)
    solution = Solution().isNumber
    test.run_tests(solution)
