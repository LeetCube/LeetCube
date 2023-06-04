from python.src.code_2709 import Solution
from python.test.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["nums"]


def test():
    test = BoilerTest(2709, input_fetcher)
    solution = Solution().canTraverseAllPairs
    test.run_tests(solution)
