class Solution:
    def defangIPaddr(self, address: str) -> str:
        defangedList = ""
        for index in range(len(address)):
            if address[index] != ".":
                defangedList += address[index]
            else:
                defangedList += "["
                defangedList += address[index]
                defangedList += "]"
        return defangedList
