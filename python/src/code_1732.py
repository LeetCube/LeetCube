class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        altitudes = [0]

        for i in range(len(gain)):
            newAltitude = altitudes[i] + gain[i]
            altitudes += [newAltitude]

        return max(altitudes)
