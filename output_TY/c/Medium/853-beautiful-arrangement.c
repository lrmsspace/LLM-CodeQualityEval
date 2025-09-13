/**https://leetcode.com/problems/beautiful-arrangement/ */
//Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
//	perm[i] is divisible by i.
//	i is divisible by perm[i].
//Given an integer n, return the number of the beautiful arrangements that you can construct.
// 
//Example 1:
//Input: n = 2
//Output: 2
//Explanation: 
//The first beautiful arrangement is [1,2]:
//    - perm[1] = 1 is divisible by i = 1
//    - perm[2] = 2 is divisible by i = 2
//The second beautiful arrangement is [2,1]:
//    - perm[1] = 2 is divisible by i = 1
//    - i = 2 is divisible by perm[2] = 1
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 15
int countArrangement(int n){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[16], b[16], c[16], d[16], e[16], f[16], g[16], h[16], i1[16], j1[16], k1[16], l1[16], m1[16], n1[16], o1[16], p1[16], q1[16], r1[16], s1[16], t1[16], u1[16], v1[16], w1[16], x1[16], y1[16], z1[16];
    for (i = 1; i <= n; i++) {
        a[i] = i;
        b[i] = 0;
        c[i] = 0;
        d[i] = 0;
        e[i] = 0;
        f[i] = 0;
        g[i] = 0;
        h[i] = 0;
        i1[i] = 0;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i != j) {
                if (a[i] % a[j] == 0) {
                    b[i]++;
                }
                if (a[j] % a[i] == 0) {
                    c[i]++;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i != j) {
                if (b[i] == c[j]) {
                    e[i]++;
                }
                if (c[i] == b[j]) {
                    f[i]++;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        ans += e[i] * f[i];
    }
    return ans;
}