from python.src.code_934 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["grid"]


def test():
    test = BoilerTest(934, input_fetcher)
    solution = Solution().shortestBridge
    test.run_tests(solution)
