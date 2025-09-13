/**https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/ */
//Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.
//The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
//Output: 20
//Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
//Example 2:
//Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
//Output: 29
//Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
//Example 3:
//Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
//Output: 31
//Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.
// 
//Constraints:
//	1 <= firstLen, secondLen <= 1000
//	2 <= firstLen + secondLen <= 1000
//	firstLen + secondLen <= nums.length <= 1000
//	0 <= nums[i] <= 1000
int maxSumTwoNoOverlap(int* nums, int numsSize, int firstLen, int secondLen) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1001] = {0};
    int b[1001] = {0};
    int c[1001] = {0};
    int d[1001] = {0};
    int e[1001] = {0};
    int f[1001] = {0};
    int g[1001] = {0};
    int h[1001] = {0};
    int ans = 0;
    for(i = 0; i < numsSize; i++) {
        a[i + 1] = a[i] + nums[i];
    }
    for(i = firstLen; i <= numsSize; i++) {
        b[i] = max(b[i - 1], a[i] - a[i - firstLen]);
    }
    for(i = numsSize - secondLen; i >= 0; i--) {
        c[i] = max(c[i + 1], a[i + secondLen] - a[i]);
    }
    for(i = firstLen; i <= numsSize - secondLen; i++) {
        ans = max(ans, b[i] + c[i]);
    }
    for(i = secondLen; i <= numsSize; i++) {
        d[i] = max(d[i - 1], a[i] - a[i - secondLen]);
    }
    for(i = numsSize - firstLen; i >= 0; i--) {
        e[i] = max(e[i + 1], a[i + firstLen] - a[i]);
    }
    for(i = secondLen; i <= numsSize - firstLen; i++) {
        ans = max(ans, d[i] + e[i]);
    }
    return ans;
}