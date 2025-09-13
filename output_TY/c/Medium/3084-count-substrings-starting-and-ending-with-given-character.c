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
    long long ans = 0;
    for (int i = 0, j = 0; i < strlen(s); i++) {
        if (s[i] == c) {
            j = i;
            while (i < strlen(s) && s[i] == c) i++;
            ans += (i - j) * (i - j + 1) / 2;
        }
    }
    return ans;

    
}