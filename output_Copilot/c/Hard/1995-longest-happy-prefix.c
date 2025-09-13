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
    int *next = (int *)malloc(sizeof(int) * (n + 1));
    next[0] = -1;
    int i = 0, j = -1;
    while (i < n) {
        if (j == -1 || s[i] == s[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    char *res = (char *)malloc(sizeof(char) * (next[n] + 1));
    for (int k = 0; k < next[n]; k++) {
        res[k] = s[k];
    }
    res[next[n]] = '\0';
    return res;    
}