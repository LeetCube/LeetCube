from python.tests.python_deps.boilerplate import BoilerTest
from python.src.code_22 import Solution

def input_fetcher(case):
    return case["input"]["n"]


def test():
    test = BoilerTest(22, input_fetcher)
    solution = Solution().generateParenthesis
    test.run_tests(solution)
