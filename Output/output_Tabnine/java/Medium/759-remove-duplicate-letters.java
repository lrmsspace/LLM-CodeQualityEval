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
        int[] count = new int[26];
        boolean[] visited = new boolean[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            count[c - 'a']--;
            if (visited[c - 'a']) continue;
            while (sb.length() > 0 && sb.charAt(sb.length() - 1) > c && count[sb.charAt(sb.length() - 1) - 'a'] > 0) {
                visited[sb.charAt(sb.length() - 1) - 'a'] = false;
                sb.deleteCharAt(sb.length() - 1);
            }
            sb.append(c);
            visited[c - 'a'] = true;
        }
        
        return sb.toString();
        
    }
}