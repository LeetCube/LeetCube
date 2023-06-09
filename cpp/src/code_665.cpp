#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

        We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

        @pre n == nums.length
        @pre 1 <= n <= 10^4
        @pre -10^5 <= nums[i] <= 10^5
    */
    bool checkPossibility(vector<int>& a) {
        bool modified = false;
        int prev = a[0];

        for (size_t i = 1; i < a.size(); i++) {
            if (a[i] < prev) {
                if (modified) return false;

                modified = true;
            }

            if (a[i] < prev && i >= 2 && a[i - 2] > a[i]) continue;

            prev = a[i];
        }

        return true;
    }
};