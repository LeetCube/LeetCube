from python.src.code_200 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["grid"]


def test():
    test = BoilerTest(200, input_fetcher)
    solution = Solution().numIslands
    test.run_tests(solution)
