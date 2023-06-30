from python.src.code_864 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["grid"]


def test():
    test = BoilerTest(864, input_fetcher)
    solution = Solution().shortestPathAllKeys
    test.run_tests(solution)
