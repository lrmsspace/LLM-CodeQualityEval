/**https://leetcode.com/problems/last-substring-in-lexicographical-order/ */
//Given a string s, return the last substring of s in lexicographical order.
// 
//Example 1:
//Input: s = "abab"
//Output: "bab"
//Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
//Example 2:
//Input: s = "leetcode"
//Output: "tcode"
// 
//Constraints:
//	1 <= s.length <= 4 * 105
//	s contains only lowercase English letters.
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0, j = 1, k = 0;
        while (j + k < n) {
            if (s[i + k] == s[j + k]) {
                ++k;
            }
            else if (s[i + k] < s[j + k]) {
                int t = max(j, i + 1);
                swap(i, j);
                j = t + k;
                k = 0;
            }
            else {
                i += k + 1;
                if (i == j) ++i;
                k = 0;
            }
        }
        return s.substr(i);
    }
};