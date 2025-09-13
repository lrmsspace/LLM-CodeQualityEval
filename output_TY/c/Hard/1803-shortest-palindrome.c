/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.
// 
//Example 1:
//Input: s = "aacecaaa"
//Output: "aaacecaaa"
//Example 2:
//Input: s = "abcd"
//Output: "dcbabcd"
// 
//Constraints:
//	0 <= s.length <= 5 * 104
//	s consists of lowercase English letters only.
char * shortestPalindrome(char * s){
    int i, j, k, n, m, l, r, t;
    char *p, *q, *r, *t1, *t2;
    n = strlen(s);
    p = (char *)malloc(n + 1);
    memcpy(p, s, n + 1);
    for (i = 0, j = n - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            p[i] = p[j] = '*';
        }
    }
    for (i = 0, j = n - 1; i <= j; i++, j--) {
        if (p[i] == '*') {
            p[i] = s[j];
        }
        if (p[j] == '*') {
            p[j] = s[i];
        }
    }
    return p;
}