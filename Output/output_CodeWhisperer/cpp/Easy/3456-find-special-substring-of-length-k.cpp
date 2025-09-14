/*
 You are given a string s and an integer k.
 Determine if there exists a substring of length exactly k in s that satisfies the following conditions:
 The substring consists of only one distinct character (e.g., "aaa" or "bbb").
 If there is a character immediately before the substring, it must be different from the character in the substring.
 If there is a character immediately after the substring, it must also be different from the character in the substring.
 Return true if such a substring exists. Otherwise, return false.
 Example 1:
 Input: s = "aaabaaa", k = 3
 Output: true
 Explanation:
 The substring s[4..6] == "aaa" satisfies the conditions.
 It has a length of 3.
 All characters are the same.
 The character before "aaa" is 'b', which is different from 'a'.
 There is no character after "aaa".
 Example 2:
 Input: s = "abc", k = 2
 Output: false
 Explanation:
 There is no substring of length 2 that consists of one distinct character and satisfies the conditions.
 Constraints:
 1 <= k <= s.length <= 100
 s consists of lowercase English letters only.
*/

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        if (k > n) return false;

        for (int i = 0; i <= n - k; ++i) {
            char c = s[i];
            bool isSpecial = true;

            if (i > 0 && s[i - 1] == c) {
                isSpecial = false;
            }

            if (i + k < n && s[i + k] == c) {
                isSpecial = false;
            }

            if (isSpecial) {
                for (int j = i + 1; j < i + k; ++j) {
                    if (s[j] != c) {
                        isSpecial = false;
                        break;
                    }
                }
            }

            if (isSpecial) {
                return true;
            }
        }

        return false;
        
    }
};