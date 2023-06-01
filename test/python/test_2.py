from BaseTest import BaseTest, build_linked_list, listnode_to_list
from src.python.code_2 import Solution


def input_fetcher(case):
    return build_linked_list(case["input"]["l1"]), build_linked_list(
        case["input"]["l2"]
    )


if __name__ == "__main__":
    test = BaseTest(2, input_fetcher, output_transformer=listnode_to_list)
    solution = Solution().addTwoNumbers
    test.run_tests(solution)
