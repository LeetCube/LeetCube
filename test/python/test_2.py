import sys
import os

sys.path.append(os.getcwd())
from .python_deps.boilerplate import BoilerTest
from .python_deps.data_structures import *
from src.python.code_2 import Solution


def input_fetcher(case):
    return build_linked_list(case["input"]["l1"]), build_linked_list(
        case["input"]["l2"]
    )


def test():
    test = BoilerTest(2, input_fetcher, output_transformer=listnode_to_list)
    solution = Solution().addTwoNumbers
    test.run_tests(solution)
