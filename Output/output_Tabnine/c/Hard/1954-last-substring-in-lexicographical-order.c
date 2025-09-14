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
    int max_len = 0;
    int max_start = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (strcmp(s + i, s + j) < 0) {
                int len = j - i;
                if (len > max_len) {
                    max_len = len;
                    max_start = i;
                }
                break;
            }
        }
    }
    
    char* result = malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + max_start, max_len);
    result[max_len] = '\0';
    
    return result;
    
}