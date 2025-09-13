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
char * longestNiceSubstring(char * s){
    int i, j, k, l, n, m, t, u, v, w, x, y, z;
    char *p, *q, *r, *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11, *s12;
    n = strlen(s);
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            s1 = (char *)malloc(j - i + 1);
            strncpy(s1, s + i, j - i);
            s1[j - i] = '\0';
            for (k = 0; k < j - i; k++) {
                if (islower(s1[k])) {
                    s2 = (char *)malloc(n - j + 1);
                }
            }
        }
    }
    return NULL;
}