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
        int i = 0, j = 1, k = 0;
        while (j + k < s.length()) {
            int t = Math.max(s.charAt(i + k), s.charAt(j + k));
            if (s.charAt(i + k) == t) {
                k++;
            } else if (s.charAt(j + k) == t) {
                i = j;
                k++;
            } else {
                j = j + k + 1;
                k = 0;
                if (j == i) j++;
            }
        }
        return s.substring(i);
  
    }
}