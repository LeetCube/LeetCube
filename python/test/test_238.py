from python.src.code_238 import Solution
from python.test.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["nums"]


def test():
    test = BoilerTest(238, input_fetcher)
    solution = Solution().productExceptSelf
    test.run_tests(solution)
