from collections import deque
from typing import List


class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        stack = deque()
        second = None

        for n in reversed(nums):
            if second and n < second:
                return True
            while stack and n > stack[-1]:
                second = stack.pop()
            stack.append(n)
        return False
