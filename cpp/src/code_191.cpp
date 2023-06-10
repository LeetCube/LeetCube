#include <cstdint>

// asdf
class Solution {
public:
    /**
        Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

        Note:
            - Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
            - In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

        @pre The input must be a binary string of length 32.
    */
    int hammingWeight(uint32_t u) {
        u -= (u >> 1) & 0x55555555;
        u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
        u = (u + (u >> 4)) & 0x0f0f0f0f;
        return (u * 0x01010101) >> 24;
    }
};