// 18. 4Sum (Medium)

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

            - 0 <= a, b, c, d < n
            - a, b, c, and d are distinct.
            - nums[a] + nums[b] + nums[c] + nums[d] == target

        You may return the answer in any order.

        @pre 1 <= nums.length <= 200
        @pre -10^9 <= nums[i] <= 10^9
        @pre -10^9 <= target <= 10^9
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        if (nums.size() < 4) return res;

        sort(nums.begin(), nums.end());

        for (size_t first = 0; first < nums.size() - 3; ++first) {
            if (first && nums[first - 1] == nums[first]) continue;

            if ((long long)nums[first] + (long long)nums[first + 1] + (long long)nums[first + 2] + (long long)nums[first + 3] > (long long)target) break;

            if ((long long)nums[first] + (long long)nums[nums.size() - 3] + (long long)nums[nums.size() - 2] + (long long)nums[nums.size() - 1] < (long long)target) continue;

            for (size_t second = first + 1; second < nums.size() - 2; ++second) {
                if (second > first + 1 && nums[second - 1] == nums[second]) continue;

                if ((long long)nums[first] + (long long)nums[second] + (long long)nums[second + 1] + (long long)nums[second + 2] > (long long)target) break;

                if ((long long)nums[first] + (long long)nums[second] + (long long)nums[nums.size() - 2] + (long long)nums[nums.size() - 1] < (long long)target) continue;

                size_t third = second + 1;
                size_t fourth = nums.size() - 1;

                while (third < fourth) {
                    long long s = (long long)nums[first] + (long long)nums[second] + (long long)nums[third] + (long long)nums[fourth];

                    if (s < (long long)target) ++third;
                    else if (s > (long long)target) --fourth;
                    else {
                        res.push_back({nums[first], nums[second], nums[third], nums[fourth]});

                        while (third < fourth && nums[third] == res.back()[2]) ++third;

                        while (third < fourth && nums[fourth] == res.back()[3]) --fourth;
                    }
                }
            }
        }

        return res;
    }
};