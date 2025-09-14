/**https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/ */
//You are given a positive integer n.
//Continuously replace n with the sum of its prime factors.
//	Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
//Return the smallest value n will take on.
// 
//Example 1:
//Input: n = 15
//Output: 5
//Explanation: Initially, n = 15.
//15 = 3 * 5, so replace n with 3 + 5 = 8.
//8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
//6 = 2 * 3, so replace n with 2 + 3 = 5.
//5 is the smallest value n will take on.
//Example 2:
//Input: n = 3
//Output: 3
//Explanation: Initially, n = 3.
//3 is the smallest value n will take on.
// 
//Constraints:
//	2 <= n <= 105
int smallestValue(int n){
    int i, j, k, l, m, a[100000], b[100000], c, d, e, f, g, h, p, q, r, s, t, u, v, w, x, y, z;
    for (i = 0; i < 100000; i++) a[i] = 0;
    for (i = 0; i < 100000; i++) b[i] = 0;
    for (i = 2; i <= n; i++) {
        if (a[i] == 0) {
            for (j = i; j <= n; j += i) a[j] = 1;
            b[i] = i;
        }
    }
    for (i = 2; i <= n; i++) {
        if (a[i] == 1) {
            c = i;
            d = 0;
            while (c <= n) {
                d += b[c];
                c += i;
            }
            b[i] = d;
        }
    }
    return b[n];
}