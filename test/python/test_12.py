from BaseTest import BaseTest
from src.python.code_12 import Solution


def input_fetcher(case):
    return case["input"]["num"]


if __name__ == "__main__":
    test = BaseTest(12, input_fetcher)
    solution = Solution().intToRoman
    test.run_tests(solution)
