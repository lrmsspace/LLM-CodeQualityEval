/**https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/ */
//You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.
//Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. If this is not possible, return -1.
//Note that an integer x divides y if y % x == 0.
// 
//Example 1:
//Input: nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]
//Output: 2
//Explanation: 
//The smallest element in [2,3,2,4,3] is 2, which does not divide all the elements of numsDivide.
//We use 2 deletions to delete the elements in nums that are equal to 2 which makes nums = [3,4,3].
//The smallest element in [3,4,3] is 3, which divides all the elements of numsDivide.
//It can be shown that 2 is the minimum number of deletions needed.
//Example 2:
//Input: nums = [4,3,6], numsDivide = [8,2,6,10]
//Output: -1
//Explanation: 
//We want the smallest element in nums to divide all the elements of numsDivide.
//There is no way to delete elements from nums to allow this.
// 
//Constraints:
//	1 <= nums.length, numsDivide.length <= 105
//	1 <= nums[i], numsDivide[i] <= 109
int minOperations(int* nums, int numsSize, int* numsDivide, int numsDivideSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1000000];
    int b[1000000];
    int c[1000000];
    int d[1000000];
    int e[1000000];
    int f[1000000];
    int g[1000000];
    int h[1000000];
    int i[1000000];
    int j[1000000];
    int k[1000000];
    int l[1000000];
    int m[1000000];
    int n[1000000];
    int o[1000000];
    int p[1000000];
    int q[1000000];
    int r[1000000];
    int s[1000000];
    int t[1000000];
    int u[1000000];
    int v[1000000];
    int w[1000000];
    int x[1000000];
    int y[1000000];
    int z[1000000];
    for (i = 0; i < numsSize; i++) {
        a[nums[i]]++;
    }
    for (i = 0; i < numsDivideSize; i++) {
        b[numsDivide[i]]++;
    }
    for (i = 0; i < 1000000; i++) {
        if (a[i] > 0 && b[i] > 0) {
            c[i] = a[i] - b[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (c[i] > 0) {
            d[i] = c[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (d[i] > 0) {
            e[i] = d[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (e[i] > 0) {
            f[i] = e[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (f[i] > 0) {
            g[i] = f[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (g[i] > 0) {
            h[i] = g[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (h[i] > 0) {
            i[i] = h[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (i[i] > 0) {
            j[i] = i[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (j[i] > 0) {
            k[i] = j[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (k[i] > 0) {
            l[i] = k[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (l[i] > 0) {
            m[i] = l[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (m[i] > 0) {
            n[i] = m[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (n[i] > 0) {
            o[i] = n[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (o[i] > 0) {
            p[i] = o[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (p[i] > 0) {
            q[i] = p[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (q[i] > 0) {
            r[i] = q[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (r[i] > 0) {
            s[i] = r[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (s[i] > 0) {
            t[i] = s[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (t[i] > 0) {
            u[i] = t[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (u[i] > 0) {
            v[i] = u[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (v[i] > 0) {
            w[i] = v[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (w[i] > 0) {
            x[i] = w[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (x[i] > 0) {
            y[i] = x[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (y[i] > 0) {
            z[i] = y[i];
        }
    }
    return z[0];
}