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
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        StringBuilder left = new StringBuilder();
        StringBuilder right = new StringBuilder();

        for (int i = 0; i < 26; i++) {
            char c = (char) ('a' + i);
            if (count[i] > 0) {
                int halfCount = count[i] / 2;
                left.append(String.valueOf(c).repeat(halfCount));
                right.insert(0, String.valueOf(c).repeat(halfCount));
            }
        }

        return left.toString() + right.toString();        
    }
}