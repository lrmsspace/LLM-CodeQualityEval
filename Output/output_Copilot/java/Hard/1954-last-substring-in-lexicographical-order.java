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
        int n = s.length();
        int i = 0, j = 1, k = 0;
        while (i + k < n && j + k < n) {
            if (s.charAt(i + k) == s.charAt(j + k)) {
                k++;
            } else if (s.charAt(i + k) < s.charAt(j + k)) {
                i += k + 1;
                if (i <= j) {
                    i = j + 1;
                }
                k = 0;
            } else {
                j += k + 1;
                if (j <= i) {
                    j = i + 1;
                }
                k = 0;
            }
        }
        return s.substring(Math.min(i, j));        
    }
}