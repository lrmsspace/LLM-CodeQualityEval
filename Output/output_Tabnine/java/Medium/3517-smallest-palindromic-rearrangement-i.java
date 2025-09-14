/*
 You are given a palindromic string s.
 Return the lexicographically smallest palindromic permutation of s.
 Example 1:
 Input: s = "z"
 Output: "z"
 Explanation:
 A string of only one character is already the lexicographically smallest palindrome.
 Example 2:
 Input: s = "babab"
 Output: "abbba"
 Explanation:
 Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
 Example 3:
 Input: s = "daccad"
 Output: "acddca"
 Explanation:
 Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
 Constraints:
 1 <= s.length <= 105
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
*/

class Solution {
    public String smallestPalindrome(String s) {
        StringBuilder sb = new StringBuilder(s);
        int n = sb.length();
        for (int i = 0; i < n / 2; i++) {
            int j = n - 1 - i;
            if (sb.charAt(i)!= sb.charAt(j)) {
                sb.setCharAt(j, sb.charAt(i));
                break;
            }
        }
        
        // Find the smallest palindrome by reversing the remaining part
        for (int i = n / 2, j = n - 1; i < j; i++, j--) {
            sb.setCharAt(i, sb.charAt(j));
        }
        
        return sb.toString();
        
    }
}