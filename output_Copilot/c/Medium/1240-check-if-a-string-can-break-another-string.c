/**https://leetcode.com/problems/check-if-a-string-can-break-another-string/ */
//Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa. In other words s2 can break s1 or vice-versa.
//A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.
// 
//Example 1:
//Input: s1 = "abc", s2 = "xya"
//Output: true
//Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
//Example 2:
//Input: s1 = "abe", s2 = "acd"
//Output: false 
//Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
//Example 3:
//Input: s1 = "leetcodee", s2 = "interview"
//Output: true
// 
//Constraints:
//	s1.length == n
//	s2.length == n
//	1 <= n <= 10^5
//	All strings consist of lowercase English letters.
bool checkIfCanBreak(char* s1, char* s2) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[26] = {0};
    int b[26] = {0};
    int c[26] = {0};
    int d[26] = {0};
    int e[26] = {0};
    int f[26] = {0};
    int g[26] = {0};
    int h[26] = {0};
    int ans1 = 0;
    int ans2 = 0;
    for(i = 0; i < strlen(s1); i++) {
        a[s1[i] - 'a']++;
    }
    for(i = 0; i < strlen(s2); i++) {
        b[s2[i] - 'a']++;
    }
    for(i = 0; i < 26; i++) {
        c[i] = a[i];
        d[i] = b[i];
    }
    for(i = 0; i < 26; i++) {
        if(a[i] > b[i]) {
            ans1 += a[i] - b[i];
            a[i] = b[i];
        } else {
            ans2 += b[i] - a[i];
            b[i] = a[i];
        }
    }
    if(ans1 == 0 || ans2 == 0) {
        return true;
    }
    for(i = 0; i < 26; i++) {
        if(a[i] > 0) {
            for(j = 0; j < 26; j++) {
                if(b[j] > 0) {
                    if(i >= j) {
                        a[i] -= b[j];
                        b[j] = 0;
                    } else {
                        b[j] -= a[i];
                        a[i] = 0;
                    }
                }
            }
        }
    }
    for(i = 0; i < 26; i++) {
        if(a[i] > 0) {
            return false;
        }
    }
    return true;
        
}