/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
char* smallestSubsequence(char* s) {
    int last[26] = {0};
    int used[26] = {0};
    int top = -1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        last[s[i] - 'a'] = i;
    }
    char *stack = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        if (used[s[i] - 'a']) {
            continue;
        }
        while (top >= 0 && stack[top] > s[i] && last[stack[top] - 'a'] > i) {
            used[stack[top] - 'a'] = 0;
            top--;
        }
        stack[++top] = s[i];
        used[s[i] - 'a'] = 1;
    }
    stack[top + 1] = '\0';
    return stack;    
}