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
    int n = strlen(s);
    int* last = (int*)malloc(sizeof(int) * 26);
    memset(last, -1, sizeof(int) * 26);
    int* used = (int*)malloc(sizeof(int) * 26);
    memset(used, 0, sizeof(int) * 26);
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }
    char* stack = (char*)malloc(sizeof(char) * (n + 1));
    int top = 0;
    for (int i = 0; i < n; i++) {
        if (used[s[i] - 'a']) {
            continue;
        }
        while (top > 0 && s[i] < stack[top - 1] && last[stack[top - 1] - 'a'] > i) {
            used[stack[--top] - 'a'] = 0;
        }
        stack[top++] = s[i];
        used[s[i] - 'a'] = 1;
    }
    stack[top] = '\0';
    return stack;
}