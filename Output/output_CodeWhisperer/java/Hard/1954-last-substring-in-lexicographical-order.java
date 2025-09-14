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
        int i = 0, j = 1, offset = 0, len = s.length();
        while (i + offset < len && j + offset < len) {
            char a = s.charAt(i + offset);
            char b = s.charAt(j + offset);
            if (a == b) {
                offset++;
            } else {
                if (a < b) {
                    i += offset + 1;
                } else {
                    j += offset + 1;
                }
                if (i == j) {
                    j++;
                }
                offset = 0;
            }
        }
        return s.substring(i);      
    }
}