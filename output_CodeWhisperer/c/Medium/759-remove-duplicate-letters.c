/**https://leetcode.com/problems/remove-duplicate-letters/ */
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
char* removeDuplicateLetters(char* s) {
    int n = strlen(s);
    int* last = (int*)malloc(sizeof(int) * 26);
    int* seen = (int*)malloc(sizeof(int) * 26);
    char* stack = (char*)malloc(sizeof(char) * (n + 1));
    int top = 0;
    for (int i = 0; i < 26; i++) {
        last[i] = -1;
        seen[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (!seen[c - 'a']) {
            while (top > 0 && c < stack[top - 1] && i < last[stack[top - 1] - 'a']) {
                seen[stack[--top] - 'a'] = 0;
            }
            stack[top++] = c;
            seen[c - 'a'] = 1;
        }
    }
    stack[top] = '\0';
    return stack;
}