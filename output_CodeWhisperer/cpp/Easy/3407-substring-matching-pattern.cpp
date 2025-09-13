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
    // Find position of * in pattern
    int starPos = p.find('*');
    
    // Split pattern into prefix and suffix
    string prefix = p.substr(0, starPos);
    string suffix = p.substr(starPos + 1);
    
    // If prefix is longer than string or suffix is longer than remaining string after prefix
    if (prefix.length() > s.length() || suffix.length() > s.length()) {
        return false;
    }
    
    // Check each possible starting position in s
    for (int i = 0; i <= s.length() - (prefix.length() + suffix.length()); i++) {
        // Check if prefix matches at current position
        bool prefixMatch = true;
        for (int j = 0; j < prefix.length(); j++) {
            if (s[i + j] != prefix[j]) {
                prefixMatch = false;
                break;
            }
        }
        
        if (!prefixMatch) continue;
        
        // Check if suffix matches at any valid position after prefix
        for (int k = i + prefix.length(); k <= s.length() - suffix.length(); k++) {
            bool suffixMatch = true;
            for (int j = 0; j < suffix.length(); j++) {
                if (s[k + j] != suffix[j]) {
                    suffixMatch = false;
                    break;
                }
            }
            if (suffixMatch) return true;
        }
    }
    
    return false;
}                
    
};