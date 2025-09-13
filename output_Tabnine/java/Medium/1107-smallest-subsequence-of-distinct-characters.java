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
        int[] count = new int[26];
        int[] pos = new int[26];
        boolean[] visited = new boolean[26];
        
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
            pos[s.charAt(i) - 'a'] = i;
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0 && (sb.isEmpty() || sb.charAt(sb.length() - 1) > i + 'a' || (sb.charAt(sb.length() - 1) == i + 'a' && pos[i] < pos[sb.charAt(sb.length() - 1) - 'a']))) {
                if (!visited[i]) {
                    visited[i] = true;
                    count[i]--;
                }
                sb.append(i + 'a');
            }
        }
        
        return sb.toString();
        
    }
}