#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an integer array nums, find the subarray with the largest sum, and return its sum.

        @pre 1 <= nums.length <= 10^5
        @pre -10^4 <= nums[i] <= 10^4
    */
    int maxSubArray(vector<int>& nums) {
        int m = numeric_limits<int>::min();
        int curr = 0;

        for (int i : nums) {
            curr = max(i, curr + i);
            m = max(m, curr);
        }

        return m;
    }
};