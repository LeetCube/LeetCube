// 215. Kth Largest Element in an Array (Medium)

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
    size_t partition(vector<int>& nums, size_t left, size_t right) {
        size_t pivot = left + rand() % (right - left + 1);
        int p = nums[pivot];
        swap(nums[pivot], nums[right]);
        size_t store = left;

        for (size_t i = left; i < right; ++i) {
            if (nums[i] < p) swap(nums[store++], nums[i]);
        }

        swap(nums[right], nums[store]);
        return store;
    }

    int select(vector<int>& nums, size_t left, size_t right, size_t k) {
        while (left < right) {
            size_t p = partition(nums, left, right);

            if (k == p) return nums[p];
            else if (k < p) right = p - 1;
            else left = p + 1;
        }

        return nums[left];
    }

public:
    /**
        Given an integer array nums and an integer k, return the kth largest
       element in the array.

        Note that it is the kth largest element in the sorted order, not the kth
       distinct element.

        You must solve it in O(n) time complexity.

        @pre 1 <= k <= nums.length <= 10^5
        @pre -10^4 <= nums[i] <= 10^4
    */
    int findKthLargest(vector<int>& nums, int k) {
        return select(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
