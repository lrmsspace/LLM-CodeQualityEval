/*
 You are given two strings s and pattern.
 A string x is called almost equal to y if you can change at most one character in x to make it identical to y.
 Return the smallest starting index of a substring in s that is almost equal to pattern. If no such index exists, return -1.
 A substring is a contiguous non-empty sequence of characters within a string.
 Example 1:
 Input: s = "abcdefg", pattern = "bcdffg"
 Output: 1
 Explanation:
 The substring s[1..6] == "bcdefg" can be converted to "bcdffg" by changing s[4] to "f".
 Example 2:
 Input: s = "ababbababa", pattern = "bacaba"
 Output: 4
 Explanation:
 The substring s[4..9] == "bababa" can be converted to "bacaba" by changing s[6] to "c".
 Example 3:
 Input: s = "abcd", pattern = "dba"
 Output: -1
 Example 4:
 Input: s = "dde", pattern = "d"
 Output: 0
 Constraints:
 1 <= pattern.length < s.length <= 105
 s and pattern consist only of lowercase English letters.
 Follow-up: Could you solve the problem if at most k consecutive characters can be changed?
*/

class Solution {
    public int minStartingIndex(String s, String pattern) {
        int n = s.length();
        int m = pattern.length();
        int[] count = new int[26];
        
        for (int i = 0; i < m; i++) {
            count[pattern.charAt(i) - 'a']++;
        }
        
        int left = 0;
        int mismatchCount = 0;
        for (int right = 0; right < n; right++) {
            count[s.charAt(right) - 'a']--;
            if (count[s.charAt(right) - 'a'] < 0) {
                mismatchCount++;
            }
            
            if (right >= m - 1) {
                if (mismatchCount <= 1) {
                    return left;
                }
                
                count[s.charAt(left) - 'a']++;
                if (count[s.charAt(left) - 'a'] > 0) {
                    mismatchCount--;
                }
                
                left++;
            }
        }
        return -1;
        
    }
}