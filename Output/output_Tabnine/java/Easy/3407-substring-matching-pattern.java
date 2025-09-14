/*
 You are given a string s and a pattern string p, where p contains exactly one '*' character.
 The '*' in p can be replaced with any sequence of zero or more characters.
 Return true if p can be made a substring of s, and false otherwise.
 Example 1:
 Input: s = "leetcode", p = "ee*e"
 Output: true
 Explanation:
 By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.
 Example 2:
 Input: s = "car", p = "c*v"
 Output: false
 Explanation:
 There is no substring matching the pattern.
 Example 3:
 Input: s = "luck", p = "u*"
 Output: true
 Explanation:
 The substrings "u", "uc", and "uck" match the pattern.
 Constraints:
 1 <= s.length <= 50
 1 <= p.length <= 50 
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly one '*'
*/

class Solution {
    public boolean hasMatch(String s, String p) {
        // Base case: If p is empty, then s must also be empty
        if (p.isEmpty()) {
            return s.isEmpty();
        }
        
        // If p contains a '*', we can match zero or more occurrences of the previous character
        if (p.length() > 1 && p.charAt(1) == '*') {
            // If the previous character in p is not present in s, then we can ignore the '*'
            if (s.isEmpty() || s.charAt(0)!= p.charAt(0)) {
                return hasMatch(s, p.substring(2));
            }
            // If the previous character in p is present in s, we can match zero or more occurrences of it
            else {
                return hasMatch(s, p) || hasMatch(s.substring(1), p);
            }
        }
        // If p does not contain a '*', we must match the current character in s with the current character in p
        else {
            return!s.isEmpty() && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') && hasMatch(s.substring(1), p.substring(1));
        }
        // If we reach here, it means that the current characters in s and p do not match, and we should return false
        return false;
        
    }
}