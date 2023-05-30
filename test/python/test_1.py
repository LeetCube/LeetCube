from BaseTest import BaseTest
from src.python.code_1 import Solution


def input_fetcher(case):
    return case['input']['nums'], case['input']['target']


if __name__ == '__main__':
    test = BaseTest(1, input_fetcher)
    solution = Solution().twoSum
    test.run_tests(solution)
