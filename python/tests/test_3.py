from python.src.code_3 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["s"]


def test():
    test = BoilerTest(3, input_fetcher)
    solution = Solution().lengthOfLongestSubstring
    test.run_tests(solution)
