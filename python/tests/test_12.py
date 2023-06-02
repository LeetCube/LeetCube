from python.src.code_12 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["num"]


def test():
    test = BoilerTest(12, input_fetcher)
    solution = Solution().intToRoman
    test.run_tests(solution)
