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
    int len = strlen(s);
    if (len == 0) {
        return s;
    }
    int last[26] = {0};
    for (int i = 0; i < len; i++) {
        last[s[i] - 'a'] = i;
    }
    int stack[26] = {0};
    int stackSize = 0;
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (stack[c] == 0) {
            while (stackSize > 0 && stack[stack[stackSize - 1]] > c && last[stack[stackSize - 1]] > i) {
                stackSize--;
            }
            stack[stackSize++] = c;
        }
    }
    char* ret = (char*)malloc(stackSize + 1);
    for (int i = 0; i < stackSize; i++) {
        ret[i] = stack[i] + 'a';
    }
    ret[stackSize] = '\0';
    return ret;    
}