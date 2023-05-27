// 16. 3Sum Closest (Medium)

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

        Return the sum of the three integers.

        You may assume that each input would have exactly one solution.

        @pre 3 <= nums.length <= 500
        @pre -1000 <= nums[i] <= 1000
        @pre -10^4 <= target <= 10^4
    */
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int soln;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (sum < target)
                    j++;
                else
                    k--;
                if (abs(sum - target) < abs(soln - target))
                    soln = sum;
            }
        }
        return soln;
    }
};
