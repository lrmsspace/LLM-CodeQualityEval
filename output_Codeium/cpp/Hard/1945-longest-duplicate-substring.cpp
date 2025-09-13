/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        string longest;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string substr = s.substr(i, j - i);
                int count = 0;
                for (int k = 0; k < n - substr.size() + 1; ++k) {
                    if (s.substr(k, substr.size()) == substr) {
                        ++count;
                    }
                }
                if (count > 1 && substr.size() > maxLen) {
                    maxLen = substr.size();
                    longest = substr;
                }
            }
        }
        return longest;
    }
};