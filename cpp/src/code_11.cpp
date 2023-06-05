#include <vector>

using namespace std;

class Solution {
public:
    /**
        You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

        Find two lines that together with the x-axis form a container, such that the container contains the most water.

        Return the maximum amount of water a container can store.

        Notice that you may not slant the container.

        @pre n == height.length
        @pre 2 <= n <= 10^5
        @pre 0 <= height[i] <= 10^4
    */
    int maxArea(vector<int>& height) {
        int first = 0, second = height.size() - 1;
        int max_area = 0;

        while (first != second) {
            max_area = max(max_area, (second - first) * min(height[first], height[second]));

            if (height[first] < height[second]) ++first;
            else --second;
        }

        return max_area;
    }
};