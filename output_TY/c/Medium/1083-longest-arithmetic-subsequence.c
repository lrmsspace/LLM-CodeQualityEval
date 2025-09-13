/**https://leetcode.com/problems/longest-arithmetic-subsequence/ */
//Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
//Note that:
//	A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//	A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
// 
//Example 1:
//Input: nums = [3,6,9,12]
//Output: 4
//Explanation:  The whole array is an arithmetic sequence with steps of length = 3.
//Example 2:
//Input: nums = [9,4,7,2,10]
//Output: 3
//Explanation:  The longest arithmetic subsequence is [4,7,10].
//Example 3:
//Input: nums = [20,1,15,3,10,5,8]
//Output: 4
//Explanation:  The longest arithmetic subsequence is [20,15,10,5].
// 
//Constraints:
//	2 <= nums.length <= 1000
//	0 <= nums[i] <= 500
int longestArithSeqLength(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1000][501], b[1000][501], c[1000][501], d[1000][501], e[1000][501], f[1000][501], g[1000][501], h[1000][501], i1, j1, k1, l1, m1, n1, o1, p1, q1;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            k = nums[j] - nums[i];
            a[i][k] = 2;
            b[i][k] = j;
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j =0; j < 501; j++) {
            if (a[i][j] > 1) {
                a[i][j] += a[b[i][j]][j];
            }
        }
    }   
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 501; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}