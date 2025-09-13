/*
 Given a string s, find any substring of length 2 which is also present in the reverse of s.
 Return true if such a substring exists, and false otherwise.
 Example 1:
 Input: s = "leetcode"
 Output: true
 Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".
 Example 2:
 Input: s = "abcba"
 Output: true
 Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".
 Example 3:
 Input: s = "abcd"
 Output: false
 Explanation: There is no substring of length 2 in s, which is also present in the reverse of s.
 Constraints:
 1 <= s.length <= 100
 s consists only of lowercase English letters.
*/

class Solution {
    public boolean isSubstringPresent(String s) {
        int n = s.length();
        if (n < 2) {
            return false; // No substring of length 2 possible
        }

        // Check all substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            String substring = s.substring(i, i + 2);
            String reversedSubstring = new StringBuilder(substring).reverse().toString();
            if (s.contains(reversedSubstring)) {
                return true; // Found a valid substring
            }
        }

        return false; // No valid substring found
        
    }
}