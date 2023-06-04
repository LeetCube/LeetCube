from python.src.code_547 import Solution
from python.test.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["isConnected"]


def test():
    test = BoilerTest(547, input_fetcher)
    solution = Solution().findCircleNum
    test.run_tests(solution)
