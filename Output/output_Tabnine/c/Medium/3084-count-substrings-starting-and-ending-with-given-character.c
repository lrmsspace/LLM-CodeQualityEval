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

long long countSubstrings(char* s, char c) {
    int n = strlen(s);
    long long count = 0;
    
    // Count substrings starting with c
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            count += (i + 1);
        }
    }
    
    // Count substrings ending with c
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) {
            count += (n - i);
        }
    }
    
    // Count substrings with c as the middle character
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == c && s[i + 1] == c) {
            count++;
        }
    }
    
    return count;
    
}