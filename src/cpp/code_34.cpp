// 34. Find First and Last Position of Element in Sorted Array (Medium)

#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

        If target is not found in the array, return [-1, -1].

        You must write an algorithm with O(log n) runtime complexity.

        @pre 0 <= nums.length <= 10^5
        @pre -10^9 <= nums[i] <= 10^9
        @pre nums is a non-decreasing array.
        @pre -10^9 <= target <= 10^9
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        size_t lower = 0, lo = 0, hi = nums.size();

        while (lo < hi) {
            size_t mid = (lo + hi) / 2;

            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }

        if (lo == nums.size() || nums[lo] != target) return {-1, -1};

        lower = lo;
        hi = nums.size();

        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (nums[mid] <= target) lo = mid + 1;
            else hi = mid;
        }

        return {(int)lower, (int)lo - 1};
    }
};