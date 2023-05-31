from BaseTest import BaseTest
from src.python.code_934 import Solution


def input_fetcher(case):
    return case["input"]["grid"]


if __name__ == "__main__":
    test = BaseTest(934, input_fetcher)
    solution = Solution().shortestBridge
    test.run_tests(solution)
