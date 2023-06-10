#include <vector>

using namespace std;

// asdf
class Solution {
public:
    /**
        Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

        You must implement a solution with a linear runtime complexity and use only constant extra space.

        @pre 1 <= nums.length <= 3 * 10^4
        @pre -3 * 10^4 <= nums[i] <= 3 * 10^4
        @pre Each element in the array appears twice except for one element which appears only once.
    */
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int n : nums) res ^= n;

        return res;
    }
};