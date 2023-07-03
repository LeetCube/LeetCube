from python.src.code_2305 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["cookies"], case["input"]["k"]


def test():
    test = BoilerTest(2305, input_fetcher)
    solution = Solution().distributeCookies
    test.run_tests(solution)
