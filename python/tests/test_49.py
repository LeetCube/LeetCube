from python.src.code_49 import Solution
from python.tests.python_deps.boilerplate import BoilerTest
from python.tests.python_deps.data_structures import nested_list_contents_comparator


def input_fetcher(case):
    return case["input"]["strs"]


def test():
    test = BoilerTest(
        49, input_fetcher, output_comparator=nested_list_contents_comparator
    )
    solution = Solution().groupAnagrams
    test.run_tests(solution)
