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
public:
    bool hasMatch(string s, string p) {
        size_t starPos = p.find('*');
        if (starPos == string::npos) {
            return false; // No '*' found, cannot match
        }

        // Check the prefix before '*'
        string prefix = p.substr(0, starPos);
        if (s.length() < prefix.length()) {
            return false; // Not enough characters for the prefix
        }
        if (s.substr(0, prefix.length()) != prefix) {
            return false; // Prefix does not match
        }

        // Check the suffix after '*'
        string suffix = p.substr(starPos + 1);
        if (s.length() < suffix.length()) {
            return false; // Not enough characters for the suffix
        }
        if (s.substr(s.length() - suffix.length()) != suffix) {
            return false; // Suffix does not match
        }

        return true; // Both prefix and suffix match
        
    }
};