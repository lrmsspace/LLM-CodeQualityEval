/*
 You are given a string s and a character c. Return the total number of substrings of s that start and end with c.
 Example 1:
 Input: s = "abada", c = "a"
 Output: 6
 Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".
 Example 2:
 Input: s = "zzz", c = "z"
 Output: 6
 Explanation: There are a total of 6 substrings in s and all start and end with "z".
 Constraints:
 1 <= s.length <= 105
 s and c consist only of lowercase English letters.
*/

class Solution {
    public long countSubstrings(String s, char c) {
        int n = s.length();
        long count = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == c) {
                count += (i + 1);  // Add the count of substrings starting at index i
            }
            if (i > 0 && s.charAt(i) == c && s.charAt(i - 1) == c) {
                count--;  // Subtract the count of substrings starting at index i-1, since they are counted twice
            }
        }
        return count;
        
    }
}