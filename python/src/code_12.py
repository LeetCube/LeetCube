import math


class Solution:
    def intToRoman(self, num: int) -> str:
        R = {1: "I", 5: "V", 10: "X", 50: "L", 100: "C", 500: "D", 1000: "M"}
        roman = []
        N = int(math.log10(num))
        for i in range(N, -1, -1):
            digit = num // 10**i
            num = num % 10**i
            curr1, curr5, curr10 = (
                R.get(10**i),
                R.get(5 * 10**i),
                R.get(10 * 10**i),
            )
            if 0 <= digit <= 3:
                roman.append(digit * curr1)
            elif digit == 4:
                roman.append(curr1 + curr5)
            elif 5 <= digit <= 8:
                roman.append(curr5 + (digit % 5) * curr1)
            elif digit == 9:
                roman.append(curr1 + curr10)

        answer = "".join(roman)

        return answer
