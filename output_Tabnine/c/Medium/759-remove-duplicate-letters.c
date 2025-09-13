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
    int count[26] = {0};
    int last[26] = {-1};
    int len = strlen(s);
    int top = 0;
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
        if (last[s[i] - 'a'] == -1 || last[s[i] - 'a'] < i - count[s[i] - 'a']) {
            last[s[i] - 'a'] = i;
        }
    }
    
    for (int i = 0; i < len; i++) {
        while (top > 0 && s[i] < stack[top - 1] && count[stack[top - 1] - 'a'] > 0) {
            count[stack[top - 1] - 'a']--;
            top--;
        }
        stack[top++] = s[i];
    }
    
    stack[top] = '\0';
    return stack;
    
}