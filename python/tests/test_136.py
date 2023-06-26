from python.src.code_136 import Solution
from python.tests.python_deps.boilerplate import BoilerTest


def input_fetcher(case):
    return case["input"]["nums"]


def test():
    test = BoilerTest(136, input_fetcher)
    solutionXOR = Solution().singleNumberXORSolution
    solutionFreqTable = Solution().singleNumberFreqTableSolution
    test.run_tests(solutionXOR)
    test.run_tests(solutionFreqTable)
