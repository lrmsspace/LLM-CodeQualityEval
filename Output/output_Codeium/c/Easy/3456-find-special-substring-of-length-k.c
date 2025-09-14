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
    int len = strlen(s);
    for (int i = 0; i <= len - k; i++) {
        char c = s[i];
        bool valid = true;
        if (i > 0 && s[i-1] == c) valid = false;
        if (i + k < len && s[i+k] == c) valid = false;
        for (int j = 1; j < k; j++) {
            if (s[i+j] != c) valid = false;
        }
        if (valid) return true;
    }
    return false;
}