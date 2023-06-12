from python.src.code_1444 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["pizza"], case["input"]["k"]


def test():
    test = BoilerTest(1444, input_fetcher)
    solution = Solution().ways
    test.run_tests(solution)
