from python.src.code_1108 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["address"]


def test():
    test = BoilerTest(1108, input_fetcher)
    solution = Solution().defangIPaddr
    test.run_tests(solution)
