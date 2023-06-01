// 35. Search Insert Position (Easy)

#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

        You must write an algorithm with O(log n) runtime complexity.

        @pre 1 <= nums.length <= 10^4
        @pre -10^4 <= nums[i] <= 10^4
        @pre nums contains distinct values sorted in ascending order.
        @pre -10^4 <= target <= 10^4
    */
    int searchInsert(vector<int>& nums, int target) {
        size_t lo = 0, hi = nums.size();

        while (lo < hi) {
            size_t mid = (lo + hi) / 2;

            if (target == nums[mid]) return mid;
            else lo = mid + 1;
        }

        return hi;
    }
};