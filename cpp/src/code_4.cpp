#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

        The overall run time complexity should be O(log (m+n)).

        @pre nums1.length == m
        @pre nums2.length == n
        @pre 0 <= m <= 1000
        @pre 0 <= n <= 1000
        @pre 1 <= m + n <= 2000
        @pre -10^6 <= nums1[i], nums2[i] <= 10^6
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = m * 2;

        while (lo <= hi) {
            int cut1 = (lo + hi) / 2;
            int cut2 = (m + n) - cut1;

            int L1 = cut1 == 0 ? numeric_limits<int>::min() : nums1[(cut1 - 1) / 2];
            int R1 = cut1 == m * 2 ? numeric_limits<int>::max() : nums1[cut1 / 2];
            int L2 = cut2 == 0 ? numeric_limits<int>::min() : nums2[(cut2 - 1) / 2];
            int R2 = cut2 == n * 2 ? numeric_limits<int>::max() : nums2[cut2 / 2];

            if (R1 < L2) lo = cut1 + 1;
            else if (L1 > R2) hi = cut1 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2.0;
        }

        return -1;
    }
};