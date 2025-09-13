/**https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ */
//Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1], k = 1
//Output: 1
//Example 2:
//Input: nums = [1,2], k = 4
//Output: -1
//Example 3:
//Input: nums = [2,-1,2], k = 3
//Output: 3
// 
//Constraints:
//	1 <= nums.length <= 105
//	-105 <= nums[i] <= 105
//	1 <= k <= 109
int shortestSubarray(int* nums, int numsSize, int k) {
    int *sum = (int *)malloc(sizeof(int) * (numsSize + 1));
    int *q = (int *)malloc(sizeof(int) * (numsSize + 1));
    int head = 0, tail = 0;
    int res = numsSize + 1;
    sum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
    for (int i = 0; i <= numsSize; i++) {
        while (head < tail && sum[i] - sum[q[head]] >= k) {
            res = fmin(res, i - q[head]);
            head++;
        }
        while (head < tail && sum[i] <= sum[q[tail - 1]]) {
            tail--;
        }
        q[tail++] = i;
    }
    return res == numsSize + 1 ? -1 : res;    
}