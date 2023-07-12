class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        n = len(answerKey)
        longest = 0
        count = {"T": 0, "F": 0}
        left = 0
        right = 0

        while right < n:
            count[answerKey[right]] += 1

            while min(count["T"], count["F"]) > k:
                count[answerKey[left]] -= 1
                left += 1

            longest = max(longest, right - left + 1)
            right += 1

        return longest
