/**https://leetcode.com/problems/longest-nice-substring/ */
//A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
//Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
// 
//Example 1:
//Input: s = "YazaAay"
//Output: "aAa"
//Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
//"aAa" is the longest nice substring.
//Example 2:
//Input: s = "Bb"
//Output: "Bb"
//Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
//Example 3:
//Input: s = "c"
//Output: ""
//Explanation: There are no nice substrings.
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of uppercase and lowercase English letters.
char* longestNiceSubstring(char* s) {
    int i, j, k, len = strlen(s);
    char *res = "";
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            int *flag = (int *)calloc(26, sizeof(int));
            for (k = i; k <= j; k++) {
                if (s[k] >= 'a' && s[k] <= 'z') {
                    flag[s[k] - 'a'] |= 1;
                } else {
                    flag[s[k] - 'A'] |= 2;
                }
            }
            int ok = 1;
            for (k = 0; k < 26; k++) {
                if (flag[k] != 3) {
                    ok = 0;
                    break;
                }
            }
            if (ok && j - i + 1 > strlen(res)) {
                res = (char *)realloc(res, j - i + 2);
                strncpy(res, s + i, j - i + 1);
                res[j - i + 1] = '\0';
            }
            free(flag);
        }
    }
    return res;    
}