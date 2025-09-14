/**https://leetcode.com/problems/split-the-array-to-make-coprime-products/ */
//You are given a 0-indexed integer array nums of length n.
//A split at an index i where 0 <= i <= n - 2 is called valid if the product of the first i + 1 elements and the product of the remaining elements are coprime.
//	For example, if nums = [2, 3, 3], then a split at the index i = 0 is valid because 2 and 9 are coprime, while a split at the index i = 1 is not valid because 6 and 3 are not coprime. A split at the index i = 2 is not valid because i == n - 1.
//Return the smallest index i at which the array can be split validly or -1 if there is no such split.
//Two values val1 and val2 are coprime if gcd(val1, val2) == 1 where gcd(val1, val2) is the greatest common divisor of val1 and val2.
// 
//Example 1:
//Input: nums = [4,7,8,15,3,5]
//Output: 2
//Explanation: The table above shows the values of the product of the first i + 1 elements, the remaining elements, and their gcd at each index i.
//The only valid split is at index 2.
//Example 2:
//Input: nums = [4,7,15,8,3,5]
//Output: -1
//Explanation: The table above shows the values of the product of the first i + 1 elements, the remaining elements, and their gcd at each index i.
//There is no valid split.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 104
//	1 <= nums[i] <= 106
int findValidSplit(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1000000], b[1000000], c[1000000], d[1000000], e[1000000], f[1000000], g[1000000], h[1000000], i1[1000000], j1[1000000], k1[1000000], l1[1000000], m1[1000000] , n1[1000000], o1[1000000], p1[1000000], q1[1000000], r1[1000000], s1[1000000], t1[1000000], u1[1000000], v1[1000000], w1[1000000], x1[1000000], y1[1000000], z1[1000000];
    for (i = 0; i < numsSize; i++) {
        a[i] = nums[i];
        b[i] = nums[i];
        c[i] = nums[i];
        d[i] = nums[i];
        e[i] = nums[i];
        f[i] = nums[i];
        g[i] = nums[i];
        h[i] = nums[i];
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            i1[i] += a[j];
            j1[i] += b[j];
            k1[i] += c[j];
            l1[i] += d[j];
            m1[i] += e[j];
            n1[i] += f[j];
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            o1[i] += g[j];
            p1[i] += h[j];
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            q1[i] += i1[j];
            r1[i] += j1[j];
            s1[i] += k1[j];
            t1[i] += l1[j];
           u1[i] += m1[j];
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            v1[i] += o1[j];
            w1[i] += p1[j];
            x1[i] += q1[j];
            y1[i] += r1[j];
            z1[i] += s1[j];
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            if (gcd(w1[i], x1[j]) == 1) {
                return i;
            }
        }
    }
    return -1;
}