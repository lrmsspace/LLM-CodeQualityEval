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

bool hasMatch(char* s, char* p) {
    char* star = strchr(p, '*'); // Find the position of '*'
    if (!star) {
        return false; // No '*' found, cannot match
    }

    int prefixLength = star - p; // Length of the prefix before '*'
    int suffixLength = strlen(star + 1); // Length of the suffix after '*'

    // Check if there is enough length in s to match both prefix and suffix
    if (strlen(s) < prefixLength + suffixLength) {
        return false;
    }

    // Check if the prefix matches
    if (strncmp(s, p, prefixLength) != 0) {
        return false;
    }

    // Check if the suffix matches
    if (strncmp(s + strlen(s) - suffixLength, star + 1, suffixLength) != 0) {
        return false;
    }

    return true; // Both prefix and suffix match
    
}