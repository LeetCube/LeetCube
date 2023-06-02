from python.src.code_347 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["nums"], case["input"]["k"]


def test():
    test = BoilerTest(347, input_fetcher)
    solution = Solution().topKFrequent
    test.run_tests(solution)
