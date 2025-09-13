/**https://leetcode.com/problems/optimal-partition-of-string/ */
//Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.
//Return the minimum number of substrings in such a partition.
//Note that each character should belong to exactly one substring in a partition.
// 
//Example 1:
//Input: s = "abacaba"
//Output: 4
//Explanation:
//Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
//It can be shown that 4 is the minimum number of substrings needed.
//Example 2:
//Input: s = "ssssss"
//Output: 6
//Explanation:
//The only valid partition is ("s","s","s","s","s","s").
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only English lowercase letters.
int partitionString(char * s){
    int i, j, k, l, m, n, o, p, q, r, s1, t, u, v, w, x, y, z;
    int a[26] = {0};
    int b[26] = {0};
    int c[26] = {0};
    int d[26] = {0};
    int e[26] = {0};
    int f[26] = {0};
    for (i = 0; i < strlen(s); i++) {
        for (j = 0; j < 26; j++) {
            if (s[i] == j + 'a') {
                a[j] = 1;
            }
        }
        for (j = 0; j < 26; j++) {
            if (a[j] == 1) {
                b[j] =1;
            }
        }
    }
    for (i = 0; i < strlen(s); i++) {
        for (j = 0; j < 26; j++) {
            if (s[i] == j + 'a') {
                c[j] = 1;
            }
        }
        for (j = 0; j < 26; j++) {
            if (c[j] == 1) {
                d[j] =1;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        if (d[i] == 1) {
            count++;
        }
    }
    return count;
}