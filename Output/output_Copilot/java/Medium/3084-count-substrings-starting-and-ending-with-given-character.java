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
        long count = 0;
        int n = s.length();
        
        // Count occurrences of character c in the string
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == c) {
                // For each occurrence of c, count how many substrings can be formed
                // starting and ending with this occurrence of c
                count += (i + 1) * (n - i);
            }
        }
        
        return count;        
    }
}