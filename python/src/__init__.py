class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sums = defaultdict(lambda: 0)
        sums[0] = 1

        count = 0
        currsum = 0
        for n in nums:
            currsum += n
            if currsum-k in sums:
                count += sums[currsum-k]            
            sums[currsum] += 1

        return count