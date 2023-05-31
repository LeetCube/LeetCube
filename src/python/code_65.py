class Solution:
    digits = [str(i) for i in range(10)]
    signs = ["-", "+"]
    digits_and_signs = digits + signs

    def valid_digits(self, i) -> bool:
        # print(i)
        for digit in i:
            if digit not in self.digits:
                return False
        return True

    def valid_int(self, i) -> bool:
        if len(i) < 1:
            return False
        if i[0] in self.signs:
            if len(i) < 2:
                return False
            return self.valid_digits(i[1:])
        else:
            return self.valid_digits(i)

    def valid_decimal(self, i) -> bool:
        if len(i) < 1:
            return False
        if i[0] in self.signs:
            if len(i) < 2:
                return False
            i = i[1:]
        if i[0] == ".":
            if len(i) < 2:
                return False
            return self.valid_digits(i[1:])
        elif "." in i:
            sp = i.split(".")
            if len(sp) != 2:
                return False
            return self.valid_digits(sp[0]) and self.valid_digits(sp[1])

    def valid_decimal_or_int(self, i) -> bool:
        return self.valid_decimal(i) or self.valid_int(i)

    def isNumber(self, s: str) -> bool:
        s = s.lower()
        if "e" in s:
            sp = s.split("e")
            if len(sp) != 2:
                return False
            return self.valid_decimal_or_int(sp[0]) and self.valid_int(sp[1])
        else:
            return self.valid_decimal_or_int(s)


if __name__ == "__main__":
    s = Solution()
    # print(s.valid_int("+123"))
    # print(s.isNumber("+eo"))
    print(s.isNumber("4e+"))
    # for test in ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93",
    #              "-123.456e789"]:
    #     print(test, s.isNumber(test))

    # s.isNumber("123.23")
