// 5. Longest Palindromic Substring (Medium)

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given a string s, return the longest palindromic substring in s.

        @pre 1 <= s.length <= 1000
        @pre s consist of only digits and English letters.
    */
    string longestPalindrome(string s) {
        vector<short> radii(2 * s.length() + 1, 0);
        vector<char> sp(2 * s.length() + 1, '|');

        for (size_t i = 0; i < s.length(); ++i) sp[2 * i + 1] = s[i];

        short centre = 0;
        short radius = 0;

        while (centre < (short)sp.size()) {
            while (0 <= centre - (radius + 1) && centre + (radius + 1) < (short)sp.size() && sp[centre - (radius + 1)] == sp[centre + (radius + 1)]) ++radius;

            radii[centre] = radius;

            short old_centre = centre;
            short old_radius = radius;
            ++centre;
            radius = 0;

            while (centre <= old_centre + old_radius) {
                short mirrored_centre = old_centre - (centre - old_centre);
                short max_mirrored_radius = old_radius - (centre - old_centre);

                if (radii[mirrored_centre] < max_mirrored_radius) {
                    radii[centre] = radii[mirrored_centre];
                    ++centre;
                } else if (radii[mirrored_centre] > max_mirrored_radius) {
                    radii[centre] = max_mirrored_radius;
                    ++centre;
                } else {
                    radius = max_mirrored_radius;
                    break;
                }
            }
        }

        short max_size = 0;
        short idx = 0;

        for (short i = 0; i < (short)radii.size(); ++i) {
            if (radii[i] > max_size) {
                max_size = radii[i];
                idx = (i - max_size) / 2;
            }
        }

        return s.substr(idx, max_size);
    }
};