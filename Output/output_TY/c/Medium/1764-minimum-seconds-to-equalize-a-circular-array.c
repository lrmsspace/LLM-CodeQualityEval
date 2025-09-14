/**https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/ */
//You are given a 0-indexed array nums containing n integers.
//At each second, you perform the following operation on the array:
//	For every index i in the range [0, n - 1], replace nums[i] with either nums[i], nums[(i - 1 + n) % n], or nums[(i + 1) % n].
//Note that all the elements get replaced simultaneously.
//Return the minimum number of seconds needed to make all elements in the array nums equal.
// 
//Example 1:
//Input: nums = [1,2,1,2]
//Output: 1
//Explanation: We can equalize the array in 1 second in the following way:
//- At 1st second, replace values at each index with [nums[3],nums[1],nums[3],nums[3]]. After replacement, nums = [2,2,2,2].
//It can be proven that 1 second is the minimum amount of seconds needed for equalizing the array.
//Example 2:
//Input: nums = [2,1,3,3,2]
//Output: 2
//Explanation: We can equalize the array in 2 seconds in the following way:
//- At 1st second, replace values at each index with [nums[0],nums[2],nums[2],nums[2],nums[3]]. After replacement, nums = [2,3,3,3,3].
//- At 2nd second, replace values at each index with [nums[1],nums[1],nums[2],nums[3],nums[4]]. After replacement, nums = [3,3,3,3,3].
//It can be proven that 2 seconds is the minimum amount of seconds needed for equalizing the array.
//Example 3:
//Input: nums = [5,5,5,5]
//Output: 0
//Explanation: We don't need to perform any operations as all elements in the initial array are the same.
// 
//Constraints:
//	1 <= n == nums.length <= 105
//	1 <= nums[i] <= 109
int minimumSeconds(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[numsSize], b[numsSize], c[numsSize], d[numsSize], e[numsSize], f[numsSize], g[numsSize], h[numsSize], i[numsSize], j[numsSize], k[numsSize], l[numsSize], m[numsSize], n[numsSize], o[numsSize], p[numsSize], q[numsSize], r[numsSize], s[numsSize], t[numsSize], u[numsSize], v[numsSize], w[numsSize], x[numsSize], y[numsSize], z[numsSize];
    for (i = 0; i < numsSize; i++) {
        a[i] = nums[i];
        b[i] = nums[i];
        c[i] = nums[i];
        d[i] = nums[i];
        e[i] = nums[i];
        f[i] = nums[i];
        g[i] = nums[i];
        h[i] = nums[i];
        i[i] = nums[i];
        j[i] = nums[i];
        k[i] = nums[i];
        l[i] = nums[i];
        m[i] = nums[i];
        n[i] = nums[i];
        o[i] = nums[i];
        p[i] = nums[i];
        q[i] = nums[i];
        r[i] = nums[i];
        s[i] = nums[i];
        t[i] = nums[i];
        u[i] = nums[i];
        v[i] = nums[i];
        w[i] = nums[i];
        x[i] = nums[i];
        y[i] = nums[i];
        z[i] = nums[i];
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            a[j] = nums[(j - 1 + numsSize) % numsSize];
            b[j] = nums[(j + 1) % numsSize];
            c[j] = nums[j];
            d[j] = nums[(j - 1+ numsSize) % numsSize];
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            e[j] = nums[(j - 1 + numsSize) % numsSize];
            f[j] = nums[(j + 1) % numsSize];
            g[j] = nums[j];
            h[j] = nums[(j - 1+ numsSize) % numsSize];
            i[j] = nums[(j - 2 + numsSize) % numsSize];
            j[j] = nums[(j - 1 + numsSize) % numsSize];
            k[j] = nums[(j + 1) % numsSize];
            l[j] = nums[(j + 2) % numsSize];
            m[j] = nums[(j - 3 + numsSize) % numsSize];
            n[j] = nums[(j - 2 + numsSize) % numsSize];
            o[j] = nums[(j - 1 + numsSize) % numsSize];
            p[j] = nums[(j + 1) % numsSize];
            q[j] = nums[(j + 2) % numsSize];
            r[j] = nums[(j + 3) % numsSize];
            s[j] = nums[(j - 4 + numsSize) % numsSize];
            t[j] = nums[(j - 3 + numsSize) % numsSize];
            u[j] = nums[(j - 2 + numsSize) % numsSize];
            v[j] = nums[(j - 1 + numsSize) % numsSize];
            w[j] = nums[(j + 2) % numsSize];
            x[j] = nums[(j + 3) % numsSize];
            y[j] = nums[(j + 4) % numsSize];
            z[j] = nums[(j + 1) % numsSize];
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (a[j] == b[j]) {
                return 1;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (c[j] == d[j]) {
                return 2;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (e[j] == f[j]) {
                return 3;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (g[j] == h[j]) {
                return 4;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (i[j] == j[j]) {
                return 5;
            }
            if (k[j] == l[j]) {
                return 5;
            }
            if (m[j] == n[j]) {
                return 6;
            }
            if (o[j] == p[j]) {
                return 6;
            }
            if (q[j] == r[j]) {
                return 7;
            }
            if (s[j] == t[j]) {
                return 7;
            }
            if (u[j] == v[j]) {
                return 8;
            }
            if (w[j] == x[j]) {
                return 8;
            }
            if (y[j] == z[j]) {
                return 8;
            }
            if (a[j] == b[j]) {
                return 9;
            }
            if (c[j] == d[j]) {
                return 9;
            }
            if (e[j] == f[j]) {
                return 9;
            }
            if (g[j] == h[j]) {
                return 9;
            }
            return 10;
        }
    }
    return 0;
}