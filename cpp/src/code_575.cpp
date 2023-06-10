#include <bitset>
#include <vector>

using namespace std;

// asdf
class Solution {
public:
    /**
        Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

        The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

        Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

        @pre n == candyType.length
        @pre 2 <= n <= 10^4
        @pre n is even.
        @pre -10^5 <= candyType[i] <= 10^5
    */
    int distributeCandies(vector<int>& candyType) {
        bitset<200001> set;

        for (int i : candyType) set[i + 100000] = true;

        return min(set.count(), candyType.size() / 2);
    }
};