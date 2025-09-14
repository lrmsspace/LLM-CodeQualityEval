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
    int i = 0, j = 1, k = 0;
    while (j + k < n) {
        if (s[i + k] == s[j + k]) {
            k++;
        } else if (s[i + k] < s[j + k]) {
            i = i + k + 1;
            if (i > j) {
                i = j;
                j = i + 1;
            }
            k = 0;
        } else {
            j = j + k + 1;
            k = 0;
        }
        if (i + k >= j) {
            j = i + 1;
        }
    }
    return s + i;   
}