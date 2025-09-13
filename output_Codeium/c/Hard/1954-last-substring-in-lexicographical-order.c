/**https://leetcode.com/problems/last-substring-in-lexicographical-order/ */
//Given a string s, return the last substring of s in lexicographical order.
// 
//Example 1:
//Input: s = "abab"
//Output: "bab"
//Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
//Example 2:
//Input: s = "leetcode"
//Output: "tcode"
// 
//Constraints:
//	1 <= s.length <= 4 * 105
//	s contains only lowercase English letters.
char* lastSubstring(char* s) {
    int n = strlen(s);
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] > s[max_idx]) {
            max_idx = i;
        }
    }
    char* res = (char*)malloc((n - max_idx + 1) * sizeof(char));
    strncpy(res, s + max_idx, n - max_idx);
    res[n - max_idx] = '\0';
    return res;
}