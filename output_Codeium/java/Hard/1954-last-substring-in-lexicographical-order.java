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
    public String lastSubstring(String s) {
        int n = s.length(), j = 0;
        char[] cs = s.toCharArray();
        for (int i = 1; i < n; ++i) {
            if (cs[i] < cs[j]) j = i;
            else if (cs[i] == cs[j]) {
                int k = j + 1, p = i + 1;
                while (k < n && p < n && cs[k] == cs[p]) ++k, ++p;
                if (k == n || cs[k] > cs[p]) j = i;
            }
        }
        return s.substring(j);
    }
}