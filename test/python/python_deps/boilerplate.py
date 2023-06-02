import json
from typing import Union
from .data_structures import *
from timeit import default_timer as timer


class BoilerTest:
    default_output_fetcher = lambda test_case: test_case["output"]

    def __init__(
        self,
        number: Union[int, str],
        input_fetcher,
        output_fetcher=default_output_fetcher,
        output_transformer=None,
        output_comparator=None,
    ):
        self.number = number
        self.input_fetcher = input_fetcher
        self.output_fetcher = output_fetcher
        self.output_transformer = output_transformer
        self.output_comparator = output_comparator
        with open(f"../data/json_testcases/test_{number}.json", "r") as f:
            self.test_cases = json.load(f)

    def run_tests(self, solution):
        start = timer()
        for test_case in self.test_cases:
            input = self.input_fetcher(test_case)
            answer = self.output_fetcher(test_case)
            if isinstance(input, tuple):
                actual = solution(*input)
            else:
                actual = solution(input)
            if self.output_transformer is not None:
                actual = self.output_transformer(actual)

            error_msg = (
                f"Failed case. Should have been {answer}, was {actual}\n: {input}"
            )

            if self.output_comparator is not None:
                assert self.output_comparator(answer, actual), error_msg
            else:
                assert answer == actual, error_msg

        end = timer()
        print(f"\ntest_{self.number}: {(end - start):.3f}s")
