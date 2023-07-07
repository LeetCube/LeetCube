class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        longestTrueLen = self.maxConsecutiveHelper(answerKey, k, "T")
        longestFalseLen = self.maxConsecutiveHelper(answerKey, k, "F")
        return max(longestTrueLen, longestFalseLen)

    def maxConsecutiveHelper(self, answerKey: str, k: int, currAns: str) -> int:
        longest = 0
        operations = 0
        left = 0
        right = 0

        while right < len(answerKey):
            if answerKey[right] != currAns:
                operations += 1

            if operations > k or right == len(answerKey) - 1:
                numElements = right - left

                if operations <= k and right == len(answerKey) - 1:
                    numElements += 1

                if longest < numElements:
                    longest = numElements

                while operations > k and left < right:
                    if answerKey[left] != currAns:
                        operations -= 1

                    left += 1

            right += 1

        return longest
