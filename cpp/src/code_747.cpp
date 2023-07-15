#include <vector>

using namespace std;

class Solution {
public:
    /**
        You are given an integer array nums where the largest integer is unique.

        Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.

        @pre 2 <= nums.length <= 50
        @pre 0 <= nums[i] <= 100
        @pre The largest element in nums is unique.
    */
    int dominantIndex(vector<int>& nums) {
        int idx = 0, m1 = 0, m2 = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > m1) {
                m2 = m1;
                m1 = nums[i];
                idx = i;
            } else m2 = max(m2, nums[i]);
        }

        return m1 >= m2 * 2 ? idx : -1;
    }
};