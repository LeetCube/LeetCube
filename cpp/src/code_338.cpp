#include <vector>

using namespace std;

// asdf
Solution{public :
             /**
                 Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

                 @pre 0 <= n <= 10^5
             */
             vector<int>
                 countBits(int n){vector<int> res(n + 1);

for (int i = 1; i <= n; ++i) res[i] = res[i / 2] + (i % 2 == 1);

return res;
}
}
;