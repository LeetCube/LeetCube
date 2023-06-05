from python.src.code_112 import Solution
from python.tests.python_deps.boilerplate import BoilerTest
from python.tests.python_deps.data_structures import createBinaryTree


def input_fetcher(case):
    list = case["input"]["root"]
    root = createBinaryTree(list)
    return root, case["input"]["targetSum"]


def test():
    test = BoilerTest(112, input_fetcher)
    solution = Solution().hasPathSum
    test.run_tests(solution)
