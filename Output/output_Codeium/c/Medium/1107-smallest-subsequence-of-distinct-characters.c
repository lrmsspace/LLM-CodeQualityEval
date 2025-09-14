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
    int count[26] = {0};
    bool inStack[26] = {false};
    char *res = (char *)malloc(strlen(s) + 1);
    int top = -1;
    for (int i = 0; i < strlen(s); i++) {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < strlen(s); i++) {
        count[s[i] - 'a']--;
        if (inStack[s[i] - 'a']) continue;
        while (top >= 0 && res[top] > s[i]) {
            inStack[res[top] - 'a'] = false;
            top--;
        }
        res[++top] = s[i];
        inStack[s[i] - 'a'] = true;
    }
    res[++top] = '\0';
    return res;
}