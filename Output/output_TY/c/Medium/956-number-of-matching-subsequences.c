/**https://leetcode.com/problems/number-of-matching-subsequences/ */
//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//	For example, "ace" is a subsequence of "abcde".
// 
//Example 1:
//Input: s = "abcde", words = ["a","bb","acd","ace"]
//Output: 3
//Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
//Example 2:
//Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
//Output: 2
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	1 <= words.length <= 5000
//	1 <= words[i].length <= 50
//	s and words[i] consist of only lowercase English letters.
int numMatchingSubseq(char * s, char ** words, int wordsSize){
    int i, j, k, l, m, n, p, q, r, t, u, v, w, x, y, z;
    int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z; 
    a = (int *)calloc(26, sizeof(int)); 
    b = (int *)calloc(26, sizeof(int));
    c = (int *)calloc(26, sizeof(int));
    d = (int *)calloc(26, sizeof(int));
    e = (int *)calloc(26, sizeof(int));
    f = (int *)calloc(26, sizeof(int));
    g = (int *)calloc(26, sizeof(int)); 
    h = (int *)calloc(26, sizeof(int));
    i = (int *)calloc(26, sizeof(int));
        for (i = 0; i < 26; i++) {
            a[i] = -1;
            b[i] = -1;
            c[i] = -1;
            d[i] = -1;
            e[i] = -1;
            f[i] = -1;
            g[i] = -1;
            h[i] = -1;
            i[i] = -1;
        }   
        for (i = 0; i < strlen(s); i++) {
            if (s[i] == 'a') a[0] = i;
            else if (s[i] == 'b') b[0] = i;
            else if (s[i] == 'c') c[0] = i;
            else if (s[i] == 'd') d[0] = i;
            else if (s[i] == 'e') e[0] = i;
        }   
        for (i = 1; i < 6; i++) {
            if (a[i - 1] != -1) a[i] = a[i - 1] + 1;
            else a[i] = -1;
            if (b[i - 1] != -1) b[i] = b[i - 1] + 1;
            else b[i] = -1;
            if (c[i - 1] != -1) c[i] = c
        }   
        return a[5] + b[5] + c[5] + d[5] + e[5];
}