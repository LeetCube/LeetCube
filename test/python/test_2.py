import sys
import os

sys.path.append(os.getcwd())
from .python_deps.boilerplate import BoilerTest
from .python_deps.data_structures import Helpers
from src.python.code_2 import Solution


def input_fetcher(case):
    return Helpers.build_linked_list(case["input"]["l1"]), Helpers.build_linked_list(
        case["input"]["l2"]
    )


def test():
    test = BoilerTest(2, input_fetcher, output_transformer=Helpers.listnode_to_list)
    solution = Solution().addTwoNumbers
    test.run_tests(solution)
