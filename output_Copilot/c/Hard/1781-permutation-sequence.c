/**https://leetcode.com/problems/permutation-sequence/ */
//The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//	"123"
//	"132"
//	"213"
//	"231"
//	"312"
//	"321"
//Given n and k, return the kth permutation sequence.
// 
//Example 1:
//Input: n = 3, k = 3
//Output: "213"
//Example 2:
//Input: n = 4, k = 9
//Output: "2314"
//Example 3:
//Input: n = 3, k = 1
//Output: "123"
// 
//Constraints:
//	1 <= n <= 9
//	1 <= k <= n!
char* getPermutation(int n, int k) {
    int i, j, m, t, f[10] = {1};
    char *s = (char *)malloc(n + 1);
    for (i = 1; i <= n; i++) f[i] = f[i - 1] * i;
    for (i = 0; i < n; i++) s[i] = i + '1';
    s[n] = 0;
    for (i = 0, k--; i < n; i++) {
        m = k / f[n - i - 1] + i;
        for (j = m; j > i; j--) {
            t = s[j];
            s[j] = s[j - 1];
            s[j - 1] = t;
        }
        k %= f[n - i - 1];
    }
    return s;    
}