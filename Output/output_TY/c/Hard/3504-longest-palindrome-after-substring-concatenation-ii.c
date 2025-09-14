/*
 You are given two strings, s and t.
 You can create a new string by selecting a substring from s (possibly empty) and a substring from t (possibly empty), then concatenating them in order.
 Return the length of the longest palindrome that can be formed this way.
 Example 1:
 Input: s = "a", t = "a"
 Output: 2
 Explanation:
 Concatenating "a" from s and "a" from t results in "aa", which is a palindrome of length 2.
 Example 2:
 Input: s = "abc", t = "def"
 Output: 1
 Explanation:
 Since all characters are different, the longest palindrome is any single character, so the answer is 1.
 Example 3:
 Input: s = "b", t = "aaaa"
 Output: 4
 Explanation:
 Selecting "aaaa" from t is the longest palindrome, so the answer is 4.
 Example 4:
 Input: s = "abcde", t = "ecdba"
 Output: 5
 Explanation:
 Concatenating "abc" from s and "ba" from t results in "abcba", which is a palindrome of length 5.
 Constraints:
 1 <= s.length, t.length <= 1000
 s and t consist of lowercase English letters.
*/

int longestPalindrome(char* s, char* t) {
    int n = strlen(s), m = strlen(t), i, j, k, l, r, cnt = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                l = i, r = j;
                while (l >= 0 && r < m && s[l] == t[r]) {
                    l--; r++;
                }
                cnt = max(cnt, 2 * (r - j));
            }
        }
    }
    return cnt;
    
}