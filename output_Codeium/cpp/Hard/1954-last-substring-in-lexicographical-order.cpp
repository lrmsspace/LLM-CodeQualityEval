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
        int n = s.size(), i = 0, j = 1, k = 0;
        while (j < n) {
            k = (s[i] == s[j]) ? k + 1 : 0;
            if (s[i + k] < s[j + k])
                i = j + 1;
            else
                j = max(j + 1, i + 1);
        }
        return s.substr(i);
    }
};