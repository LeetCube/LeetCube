import json
from timeit import default_timer as timer
from typing import Union


def default_output_fetcher(case):
    return case['output']


class BaseTest:
    def __init__(self, number: Union[int, str], input_fetcher, output_fetcher=default_output_fetcher):
        with open(f'../test_json/test_{number}.json', 'r') as f:
            self.data = json.load(f)
            self.input_fetcher = input_fetcher
            self.output_fetcher = output_fetcher

    def run_tests(self, solution):
        start = timer()
        for case in self.data:
            input = self.input_fetcher(case)
            answer = self.output_fetcher(case)
            assert solution(input) == answer, \
                f"Failed case. Should have been {answer}: {input}"

        end = timer()
        print(f"Elapsed time: {(end - start) * 1000: .0f} ms")

