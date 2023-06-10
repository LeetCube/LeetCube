#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// asdf
class Solution {
    class DSet {
    public:
        vector<int> arr;

        DSet(size_t n) {
            arr = vector<int>(n, -1);
        }

        int Find(int a) {
            if (arr[a] < 0) return a;

            return arr[a] = Find(arr[a]);
        }

        void Union(int a, int b) {
            int root1 = Find(a);
            int root2 = Find(b);

            if (root1 == root2) return;

            int new_size = arr[root1] + arr[root2];

            if (arr[root1] <= arr[root2]) {
                arr[root2] = root1;
                arr[root1] = new_size;
            } else {
                arr[root1] = root2;
                arr[root2] = new_size;
            }
        }

        int Count(int a) {
            return -arr[Find(a)];
        }
    };

public:
    /**
        You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.

        Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.

        Return true if it is possible to traverse between all such pairs of indices, or false otherwise.

        @pre 1 <= nums.length <= 10^5
        @pre 1 <= nums[i] <= 10^5
    */
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() == 1) return true;

        unordered_set<int> s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());
        DSet dset(nums.size());
        unordered_map<int, int> idx;

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == 1) return false;

            int curr = nums[i];

            if (curr % 2 == 0) {
                // if 2 is already a divisor of a previous number, we union the two indices because they share a common factor (2)
                if (idx.find(2) != idx.end()) dset.Union(i, idx.at(2));
                // otherwise we indicate that 2 is a divisor of the number at index i, to union with future indices
                else idx[2] = i;

                while (curr % 2 == 0) curr /= 2;
            }

            if (curr % 3 == 0) {
                if (idx.find(3) != idx.end()) dset.Union(i, idx.at(3));
                else idx[3] = i;

                while (curr % 3 == 0) curr /= 3;
            }

            for (int j = 6; (j - 1) * (j - 1) <= curr; j += 6) {
                if (curr % (j - 1) == 0) {
                    if (idx.find(j - 1) != idx.end()) dset.Union(i, idx.at(j - 1));
                    else idx[j - 1] = i;

                    while (curr % (j - 1) == 0) curr /= j - 1;
                }

                if (curr % (j + 1) == 0) {
                    if (idx.find(j + 1) != idx.end()) dset.Union(i, idx.at(j + 1));
                    else idx[j + 1] = i;

                    while (curr % (j + 1) == 0) curr /= j + 1;
                }
            }

            if (curr > 1) {
                if (idx.find(curr) != idx.end()) dset.Union(i, idx.at(curr));
                else idx[curr] = i;
            }
        }

        return dset.Count(0) == (int)nums.size();
    }
};