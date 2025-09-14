/*
 You are given a string s and an integer k.
 Determine if there exists a substring of length exactly k in s that satisfies the following conditions:
 The substring consists of only one distinct character (e.g., "aaa" or "bbb").
 If there is a character immediately before the substring, it must be different from the character in the substring.
 If there is a character immediately after the substring, it must also be different from the character in the substring.
 Return true if such a substring exists. Otherwise, return false.
 Example 1:
 Input: s = "aaabaaa", k = 3
 Output: true
 Explanation:
 The substring s[4..6] == "aaa" satisfies the conditions.
 It has a length of 3.
 All characters are the same.
 The character before "aaa" is 'b', which is different from 'a'.
 There is no character after "aaa".
 Example 2:
 Input: s = "abc", k = 2
 Output: false
 Explanation:
 There is no substring of length 2 that consists of one distinct character and satisfies the conditions.
 Constraints:
 1 <= k <= s.length <= 100
 s consists of lowercase English letters only.
*/

bool hasSpecialSubstring(char* s, int k) {
    int length = strlen(s);
    
    // Check if k is greater than the string length
    if (k > length) {
        return false;
    }
    
    for (int i = 0; i <= length - k; i++) {
        // Check if the substring s[i:i+k] consists of one distinct character
        char currentChar = s[i];
        int j;
        for (j = 1; j < k; j++) {
            if (s[i + j] != currentChar) {
                break; // Found a different character
            }
        }
        
        // If we found a valid substring of length k with one distinct character
        if (j == k) {
            // Check the characters before and after the substring
            if ((i == 0 || s[i - 1] != currentChar) && 
                (i + k == length || s[i + k] != currentChar)) {
                return true; // Found a valid special substring
            }
        }
    }
    
    return false; // No valid special substring found
    
}