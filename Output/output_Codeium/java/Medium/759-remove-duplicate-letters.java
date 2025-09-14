/**https://leetcode.com/problems/remove-duplicate-letters/ */
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
class Solution {
    public String removeDuplicateLetters(String s) {
        boolean[] seen = new boolean[26];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!seen[c - 'a']) {
                while (sb.length() > 0 && sb.charAt(sb.length() - 1) > c && s.indexOf(sb.charAt(sb.length() - 1), i) != -1) {
                    seen[sb.charAt(sb.length() - 1) - 'a'] = false;
                    sb.deleteCharAt(sb.length() - 1);
                }
                seen[c - 'a'] = true;
                sb.append(c);
            }
        }
        return sb.toString();
    }
}