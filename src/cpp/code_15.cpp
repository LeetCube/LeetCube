// 15. 3Sum (Medium)

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

        Notice that the solution set must not contain duplicate triplets.

        @pre 3 <= nums.length <= 3000
        @pre -10^5 <= nums[i] <= 10^5
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> soln;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;
            int j = i + 1;
            int k = nums.size() - 1;
            if (nums[k] < 0)
                break;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    soln.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }
        vector<vector<int>> output;
        for (auto s : soln)
            output.push_back(s);
        return output;
    }
};
