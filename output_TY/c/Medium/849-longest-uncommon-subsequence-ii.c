/**https://leetcode.com/problems/longest-uncommon-subsequence-ii/ */
//Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.
//An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.
//A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.
//	For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
// 
//Example 1:
//Input: strs = ["aba","cdc","eae"]
//Output: 3
//Example 2:
//Input: strs = ["aaa","aaa","aa"]
//Output: -1
// 
//Constraints:
//	2 <= strs.length <= 50
//	1 <= strs[i].length <= 10
//	strs[i] consists of lowercase English letters.
int findLUSlength(char ** strs, int strsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[strsSize], b[strsSize], c[strsSize], d[strsSize], e[strsSize];
    int f[strsSize], g[strsSize], h[strsSize], i1, j1, k1, l1, m1, n1, o1, p1, q1, r1
    , s1, t1, u1, v1, w1, x1, y1, z1;
    for (i = 0; i < strsSize; i++) {
        a[i] = strlen(strs[i]);
    }
    for (i = 0; i < strsSize; i++) {
        for (j = 0; j < strsSize; j++) {
            if (i != j) {
                if (strcmp(strs[i], strs[j]) == 0) {
                   b[i] = 1;
                }
            }
        }
    }
    for (i = 0; i < strsSize; i++) {
        if (b[i] == 0) {
            return a[i];
        }
    }
    return 0;
}