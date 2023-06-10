#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// asdf
class Solution {
public:
    /**
        Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

        You may assume that each input would have exactly one solution, and you may not use the same element twice.

        You can return the answer in any order.

        @pre 2 <= nums.length <= 10^4
        @pre -10^9 <= nums[i] <= 10^9
        @pre -10^9 <= target <= 10^9
        @pre Only one valid answer exists.
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_of;

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (index_of.find(target - nums[i]) != index_of.end()) {
                return {i, index_of[target - nums[i]]};
            } else {
                index_of[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};