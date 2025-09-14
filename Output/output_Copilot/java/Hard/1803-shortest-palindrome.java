/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.
// 
//Example 1:
//Input: s = "aacecaaa"
//Output: "aaacecaaa"
//Example 2:
//Input: s = "abcd"
//Output: "dcbabcd"
// 
//Constraints:
//	0 <= s.length <= 5 * 104
//	s consists of lowercase English letters only.
class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length();
        if (n == 0) return s;
        int i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            if (s.charAt(i) == s.charAt(j)) {
                i--;
                j++;
            } else {
                i = n - 1;
                j = 0;
            }
        }
        String prefix = s.substring(0, j);
        String suffix = new StringBuilder(s.substring(j)).reverse().toString();
        return suffix + prefix;        
    }
}