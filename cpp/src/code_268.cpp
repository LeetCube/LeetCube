// 268. Missing Number (Easy)

#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

        @pre n == nums.length
        @pre 1 <= n <= 10^4
        @pre 0 <= nums[i] <= n
        @pre All the numbers of nums are unique.
    */
    int missingNumber(vector<int>& nums) {
        int res = nums.size();

        for (int i = 0; i < (int)nums.size(); ++i) res ^= i ^ nums[i];

        return res;
    }
};