/**https://leetcode.com/problems/minimum-cost-to-make-array-equal/ */
//You are given two 0-indexed arrays nums and cost consisting each of n positive integers.
//You can do the following operation any number of times:
//	Increase or decrease any element of the array nums by 1.
//The cost of doing one operation on the ith element is cost[i].
//Return the minimum total cost such that all the elements of the array nums become equal.
// 
//Example 1:
//Input: nums = [1,3,5,2], cost = [2,3,1,14]
//Output: 8
//Explanation: We can make all the elements equal to 2 in the following way:
//- Increase the 0th element one time. The cost is 2.
//- Decrease the 1st element one time. The cost is 3.
//- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
//The total cost is 2 + 3 + 3 = 8.
//It can be shown that we cannot make the array equal with a smaller cost.
//Example 2:
//Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
//Output: 0
//Explanation: All the elements are already equal, so no operations are needed.
// 
//Constraints:
//	n == nums.length == cost.length
//	1 <= n <= 105
//	1 <= nums[i], cost[i] <= 106
//	Test cases are generated in a way that the output doesn't exceed 253-1
long long minCost(int* nums, int numsSize, int* cost, int costSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100000], b[100000], c[100000], d[100000], e[100000], f[100000], g[100000], h[100000], i1, i2, i3, i4, i5, i6, i7, i8,i9, i10;
    for (i = 0; i < numsSize; i++) {
        a[nums[i]] += cost[i];
    }
    for (i = 0; i < 100000; i++) {
        if (a[i] != 0) {
            b[i1] = a[i];
            c[i1] = i;
            i1++;
        }
    }
    for (i = 0; i < i1; i++) {
        for (j = i + 1; j < i1; j++) {
            if (c[i] > c[j]) {
                i2 = c[i];
                c[i] = c[j];
                c[j] = i2;
                i2 = b[i];
                b[i] = b[j];
               b[j] = i2;
            }
        }
    }
    for (i = 0; i < i1; i++) {
        d[i] = b[i];
        e[i] = c[i];
    }
    for (i = 0; i < i1; i++) {
        for (j = i + 1; j < i1; j++) {
            if (e[i] > e[j]) {
                i2 = e[i];
                e[i] = e[j];
                e[j] = i2;
                i2 = d[i];
                d[i] = d[j];
                d[j] = i2;
            }
        }
    }
    for (i = 0; i < i1; i++) {
        f[i] = d[i];
        g[i] = e[i];
        h[i] = b[i];
        d[i] = 0;
        e[i] = 0;
        b[i] = 0;
        for (j = 0; j < numsSize; j++) {
            if (nums[j] == g[i]) {
                d[i] += cost[j];
            }
        }
    }
    for (i = 0; i < i1; i++) {
        for (j = i + 1; j < i1; j++) {
            if (g[i] > g[j]) {
                i2 = g[i];
                g[i] = g[j];
                g[j] = i2;
                i2 = f[i];
                f[i] = f[j];
                f[j] = i2;
                i2 = h[i];
            }
        }
    }
    for (i = 0; i < i1; i++) {
        for (j = 0; j < i1; j++) {
            if (g[i] == g[j]) {
                i2 = f[i];
                f[i] = f[j];
                f[j] = i2;
                i2 = h[i];
                h[i] = h[j];
                h[j] = i2;
            }
        }
        for (j = 0; j < i1; j++) {
            if (g[i] == g[j]) {
                i2 = f[i];
                f[i] = f[j];
                f[j] = i2;
                i2 = h[i];
                h[i] = h[j];
                h[j] = i2;
            }
            for (k = 0; k < i1; k++) {
                if (g[i] == g[k]) {
                    i2 = f[i];
                    f[i] = f[k];
                    f[k] = i2;
                    i2 = h[i];
                    h[i] = h[k];
                    h[k] = i2;
                }
            }
            for (l = 0; l < i1; l++) {
                if (g[i] == g[l]) {
                    i2 = f[i];
                    f[i] = f[l];
                    f[l] = i2;
                    i2 = h[i];
                    h[i] = h[l];
                    h[l] = i2;
                }
            }
            for (m = 0; m < i1; m++) {
                if (g[i] == g[m]) {
                    i2 = f[i];
                    f[i] = f[m];
                    f[m] = i2;
                    i2 = h[i];
                    h[i] = h[m];
                    h[m] = i2;
                }
            }
            for (n = 0; n < i1; n++) {
                if (g[i] == g[n]) {
                    i2 = f[i];
                    f[i] = f[n];
                    f[n] = i2;
                    i2 = h[i];
                    h[i] = h[n];
                    h[n] = i2;
                }
            }
            for (o = 0; o < i1; o++) {
                if (g[i] == g[o]) {
                    i2 = f[i];
                    f[i] = f[o];
                    f[o] = i2;
                    i2 = h[i];
                    h[i] = h[o];
                    h[o] = i2;
                }
            }
            for (p = 0; p < i1; p++) {
                if (g[i] == g[p]) {
                    i2 = f[i];
                    f[i] = f[p];
                    f[p] = i2;
                    i2 = h[i];
                    h[i] = h[p];
                    h[p] = i2;
                }
            }
        }
    }
    
}