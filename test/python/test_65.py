from BaseTest import BaseTest
from src.python.code_65 import Solution


def input_fetcher(case):
    return case["input"]["s"]


def make_case(s, out):
    return {"contributor": "phaserush", "input": {"s": s}, "output": out}


if __name__ == "__main__":
    # l = ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
    # l2 = ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
    # import json
    # cases = [make_case(li, True) for li in l] + [make_case(li2, False) for li2 in l2]
    # print(json.dumps(cases, indent=4))

    test = BaseTest(65, input_fetcher)
    solution = Solution().isNumber
    test.run_tests(solution)
