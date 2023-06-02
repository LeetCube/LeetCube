from BaseTest import BaseTest
from src.python.code_22 import Solution


def input_fetcher(case):
    return case["input"]["n"]


if __name__ == "__main__":
    test = BaseTest(22, input_fetcher)
    solution = Solution().generateParenthesis
    test.run_tests(solution)
