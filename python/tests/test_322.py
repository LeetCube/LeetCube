from python.src.code_322 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["coins"], case["input"]["amount"]


def test():
    test = BoilerTest(322, input_fetcher)
    solution = Solution().coinChange
    test.run_tests(solution)
