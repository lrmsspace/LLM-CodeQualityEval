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
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        String reversed = sb.toString();
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            if (s.substring(0, n - i).equals(reversed.substring(i))) {
                return reversed.substring(0, i) + s;
            }
        }
        return s + reversed;  // If no palindrome is found, return the original string plus its reversed version
        
    }
}