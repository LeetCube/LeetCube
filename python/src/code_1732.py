from typing import List


class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        max_altitude = 0
        curr_altitude = 0

        for g in gain:
            curr_altitude += g
            max_altitude = max(max_altitude, curr_altitude)

        return max_altitude
