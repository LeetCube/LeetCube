from python.src.code_17 import Solution
from python.test.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["digits"]


def test():
    test = BoilerTest(17, input_fetcher)
    solution = Solution().letterCombinations
    test.run_tests(solution)
