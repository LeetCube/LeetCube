// 1780. Check if Number is a Sum of Powers of Three (Medium)

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int h = 1;
        while (h <= n) {
            h = h * 3;
        }
        h = h / 3;
        if (n - h >= h) {
            return false;
        } else if (n - h == 0) {
            return true;
        } else {
            return true && checkPowersOfThree(n - h);
        }
    }
};