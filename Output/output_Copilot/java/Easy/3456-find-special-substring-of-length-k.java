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

class Solution {
    public boolean hasSpecialSubstring(String s, int k) {
        int n = s.length();
        
        // Check if k is greater than the length of the string
        if (k > n) {
            return false;
        }
        
        // Iterate through the string to find a valid substring
        for (int i = 0; i <= n - k; i++) {
            String substring = s.substring(i, i + k);
            
            // Check if all characters in the substring are the same
            boolean allSame = true;
            char firstChar = substring.charAt(0);
            for (int j = 1; j < k; j++) {
                if (substring.charAt(j) != firstChar) {
                    allSame = false;
                    break;
                }
            }
            
            // If all characters are the same, check surrounding characters
            if (allSame) {
                char beforeChar = (i > 0) ? s.charAt(i - 1) : '\0'; // Character before the substring
                char afterChar = (i + k < n) ? s.charAt(i + k) : '\0'; // Character after the substring
                
                // Check if surrounding characters are different from the substring character
                if (beforeChar != firstChar && afterChar != firstChar) {
                    return true;
                }
            }
        }
        
        return false; // No valid substring found
        
    }
}