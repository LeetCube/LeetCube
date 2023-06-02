import json
from typing import Union
from .data_structures import *


class Test:
    default_output_fetcher = lambda test_case: test_case["output"]

    def __init__(
        self,
        number: Union[int, str],
        input_fetcher,
        output_fetcher=default_output_fetcher,
        output_transformer=None,
        output_comparator=None,
    ):
        with open(f"test/test_json/test_{number}.json", "r") as f:
            self.data = json.load(f)
            self.input_fetcher = input_fetcher
            self.output_fetcher = output_fetcher
            self.output_transformer = output_transformer
            self.output_comparator = output_comparator

    def run_tests(self, solution):
        for case in self.data:
            input = self.input_fetcher(case)
            answer = self.output_fetcher(case)
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
