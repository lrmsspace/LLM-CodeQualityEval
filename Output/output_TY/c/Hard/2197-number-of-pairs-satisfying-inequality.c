/**https://leetcode.com/problems/number-of-pairs-satisfying-inequality/ */
//You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:
//	0 <= i < j <= n - 1 and
//	nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
//Return the number of pairs that satisfy the conditions.
// 
//Example 1:
//Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
//Output: 3
//Explanation:
//There are 3 pairs that satisfy the conditions:
//1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. Since i < j and 1 <= 1, this pair satisfies the conditions.
//2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. Since i < j and -2 <= 2, this pair satisfies the conditions.
//3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. Since i < j and -3 <= 2, this pair satisfies the conditions.
//Therefore, we return 3.
//Example 2:
//Input: nums1 = [3,-1], nums2 = [-2,2], diff = -1
//Output: 0
//Explanation:
//Since there does not exist any pair that satisfies the conditions, we return 0.
// 
//Constraints:
//	n == nums1.length == nums2.length
//	2 <= n <= 105
//	-104 <= nums1[i], nums2[i] <= 104
//	-104 <= diff <= 104
long long numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int diff){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100000], b[100000], c[100000], d[100000], e[100000], f[100000], g[100000], h[100000], i[100000], j[100000], k[100000], l[100000], m[100000], n[100000], o[100000], p[100000], q[100000], r[100000], s[100000], t[100000], u[100000], v[100000], w[100000], x[100000], y[100000], z[100000];
    for (i = 0; i < nums1Size; i++) {
        a[i] = nums1[i] - nums2[i];
    }
    for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (a[i] > a[j]) {
                b[i]++;
            }
        }
    }
    for (i = 0; i < nums1Size; i++) {
        c[i] = a[i] - diff;
    }
    for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (c[i] > c[j]) {
                d[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {
        e[i] = a[i] + diff;
    }
    for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (e[i] > e[j]) {
                f[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {
        g[i] = a[i] + a[i];
    }
    for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (g[i] > g[j]) {
                h[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {

        k[i] = a[i] - a[i];
    }

    for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (k[i] > k[j]) {
                l[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {

        m[i] = a[i] + a[i];
        n[i] = a[i] + a[i];
        o[i] = a[i] + a[i];
        p[i] = a[i] + a[i];
        q[i] = a[i] + a[i];
        r[i] = a[i] + a[i];
        s[i] = a[i] + a[i];
        t[i] = a[i] + a[i];
        u[i] = a[i] + a[i];
        v[i] = a[i] + a[i];
        w[i] = a[i] + a[i];
        x[i] = a[i] + a[i];
        y[i] = a[i] + a[i];
        z[i] = a[i] + a[i];
   }
   for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (m[i] > m[j]) {
                n[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (o[i] > o[j]) {
                p[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (q[i] > q[j]) {
                r[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (s[i] > s[j]) {
                t[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (u[i] > u[j]) {
                v[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (w[i] > w[j]) {
                x[i]++;
            }
        }
   }
   for (i = 0; i < nums1Size; i++) {
        for (j = i + 1; j < nums1Size; j++) {
            if (y[i] > y[j]) {
                z[i]++;
            }
        }
   }
   return (long long)b[0] + d[0] + f[0] + h[0] + l[0] + n[0] + p[0] + r[0] + t[0] + v[0] + x[0] + z[0];
}