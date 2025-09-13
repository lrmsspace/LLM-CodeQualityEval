/**https://leetcode.com/problems/longest-happy-prefix/ */
//A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
//Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
// 
//Example 1:
//Input: s = "level"
//Output: "l"
//Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
//Example 2:
//Input: s = "ababab"
//Output: "abab"
//Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
// 
//Constraints:
//	1 <= s.length <= 105
//	s contains only lowercase English letters.
char* longestPrefix(char* s) {
    
    int n = strlen(s);
    int* next = (int*)malloc(sizeof(int) * n);
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
    int len = next[n - 1];
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    strncpy(res, s, len);
    res[len] = '\0';
    free(next);
    return res;
}