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
        int n = s.length();
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        
        StringBuilder leftHalf = new StringBuilder();
        char middleChar = 0;
        boolean hasMiddleChar = false;
        
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                if (hasMiddleChar) {
                    return ""; // Impossible to form a palindrome
                }
                hasMiddleChar = true;
                middleChar = (char) (i + 'a');
            }
            for (int j = 0; j < count[i] / 2; j++) {
                leftHalf.append((char) (i + 'a'));
            }
        }
        
        StringBuilder rightHalf = new StringBuilder(leftHalf).reverse();
        if (hasMiddleChar) {
            leftHalf.append(middleChar);
        }
        leftHalf.append(rightHalf);
        
        return leftHalf.toString();

    }
}