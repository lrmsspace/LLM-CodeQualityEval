/*
 You are given two strings, s and t.
 You can create a new string by selecting a substring from s (possibly empty) and a substring from t (possibly empty), then concatenating them in order.
 Return the length of the longest palindrome that can be formed this way.
 Example 1:
 Input: s = "a", t = "a"
 Output: 2
 Explanation:
 Concatenating "a" from s and "a" from t results in "aa", which is a palindrome of length 2.
 Example 2:
 Input: s = "abc", t = "def"
 Output: 1
 Explanation:
 Since all characters are different, the longest palindrome is any single character, so the answer is 1.
 Example 3:
 Input: s = "b", t = "aaaa"
 Output: 4
 Explanation:
 Selecting "aaaa" from t is the longest palindrome, so the answer is 4.
 Example 4:
 Input: s = "abcde", t = "ecdba"
 Output: 5
 Explanation:
 Concatenating "abc" from s and "ba" from t results in "abcba", which is a palindrome of length 5.
 Constraints:
 1 <= s.length, t.length <= 1000
 s and t consist of lowercase English letters.
*/

class Solution {
    public int longestPalindrome(String s, String t) {
        int[] countS = new int[26];
        int[] countT = new int[26];

        // Count characters in s
        for (char c : s.toCharArray()) {
            countS[c - 'a']++;
        }

        // Count characters in t
        for (char c : t.toCharArray()) {
            countT[c - 'a']++;
        }

        int length = 0;
        boolean hasOdd = false;

        // Calculate the maximum length of palindrome
        for (int i = 0; i < 26; i++) {
            if (countS[i] > 0 && countT[i] > 0) {
                length += Math.min(countS[i], countT[i]) * 2;
                if (Math.min(countS[i], countT[i]) % 2 == 1) {
                    hasOdd = true;
                }
            }
        }

        // If there's at least one character with an odd count, we can add one more character to the palindrome
        if (hasOdd) {
            length++;
        }

        return length;        
    }
}