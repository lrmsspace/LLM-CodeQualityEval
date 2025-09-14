/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
class Solution {
    public String smallestSubsequence(String s) {
        int n = s.length();
        int[] last = new int[26];
        Arrays.fill(last, -1);
        boolean[] seen = new boolean[26];
        for (int i = 0; i < n; i++) {
            last[s.charAt(i) - 'a'] = i;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (seen[s.charAt(i) - 'a']) {
                continue;
            }
            while (last[sb.charAt(sb.length() - 1) - 'a'] > i) {
                seen[sb.charAt(sb.length() - 1) - 'a'] = false;
                sb.deleteCharAt(sb.length() - 1);
            }
            sb.append(s.charAt(i));
            seen[s.charAt(i) - 'a'] = true;
        }
        return sb.toString();
    }
}