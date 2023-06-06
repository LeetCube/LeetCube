class Solution {
public:
    /**
        Given two integers a and b, return the sum of the two integers without using the operators + and -.

        @pre -1000 <= a, b <= 1000
    */
    int getSum(int a, int b) {
        return !b ? a : getSum(a ^ b, (a & b) << 1);
    }
};