/*
 You are given an array of integers nums.
 Your task is to find the length of the longest subsequence seq of nums, such that the absolute differences between consecutive elements form a non-increasing sequence of integers. In other words, for a subsequence seq0, seq1, seq2, ..., seqm of nums, |seq1 - seq0| >= |seq2 - seq1| >= ... >= |seqm - seqm - 1|.
 Return the length of such a subsequence.
 Example 1:
 Input: nums = [16,6,3]
 Output: 3
 Explanation: 
 The longest subsequence is [16, 6, 3] with the absolute adjacent differences [10, 3].
 Example 2:
 Input: nums = [6,5,3,4,2,1]
 Output: 4
 Explanation:
 The longest subsequence is [6, 4, 2, 1] with the absolute adjacent differences [2, 2, 1].
 Example 3:
 Input: nums = [10,20,10,19,10,20]
 Output: 5
 Explanation: 
 The longest subsequence is [10, 20, 10, 19, 10] with the absolute adjacent differences [10, 10, 9, 9].
 Constraints:
 2 <= nums.length <= 104
 1 <= nums[i] <= 300
*/

int longestSubsequence(int* nums, int numsSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[300], b[300], c[300], d[300], e[300], f[300], g[300], h[300], i[300], j[300], k[300], l[300], m[300], n[300], o[300], p[300], q[300], r[300], s[300], t[300], u[300], v[300], w[300], x[300], y[300], z[300];
    int max = 0;
    for (i = 0; i < numsSize; i++) {
        a[nums[i]] = 1;
    }
    for (i = 0; i < numsSize; i++) {
        if (a[nums[i]] > max) {
            max = a[nums[i]];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (a[nums[i]] == max) {
            b[nums[i]] = 1;
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (b[nums[i]] > max) {
            max = b[nums[i]];
        }
    }
    return max; 
}