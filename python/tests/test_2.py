from python.src.code_2 import Solution
from python.tests.python_deps.boilerplate import BoilerTest
from python.tests.python_deps.data_structures import build_linked_list, listnode_to_list


def input_fetcher(case):
    return build_linked_list(case["input"]["l1"]), build_linked_list(
        case["input"]["l2"]
    )


def test():
    test = BoilerTest(2, input_fetcher, output_transformer=listnode_to_list)
    solution = Solution().addTwoNumbers
    test.run_tests(solution)
