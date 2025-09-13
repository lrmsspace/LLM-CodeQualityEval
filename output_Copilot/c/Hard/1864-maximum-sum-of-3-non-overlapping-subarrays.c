/**https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ */
//Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
// 
//Example 1:
//Input: nums = [1,2,1,2,6,7,5,1], k = 2
//Output: [0,3,5]
//Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
//We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
//Example 2:
//Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
//Output: [0,2,4]
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] < 216
//	1 <= k <= floor(nums.length / 3)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    int n = numsSize;
    int *sum = (int *)malloc(sizeof(int) * (n + 1));
    int *left = (int *)malloc(sizeof(int) * n);
    int *right = (int *)malloc(sizeof(int) * n);
    int *dp = (int *)malloc(sizeof(int) * n);
    int *ans = (int *)malloc(sizeof(int) * 3);
    int i, j, t, max, total, l, r;
    sum[0] = 0;
    for (i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
    total = sum[k] - sum[0];
    for (i = k; i < n; i++) {
        if (sum[i + 1] - sum[i + 1 - k] > total) {
            total = sum[i + 1] - sum[i + 1 - k];
            left[i] = i + 1 - k;
        } else {
            left[i] = left[i - 1];
        }
    }
    right[n - k] = n - k;
    total = sum[n] - sum[n - k];
    for (i = n - k - 1; i >= 0; i--) {
        if (sum[i + k] - sum[i] >= total) {
            total = sum[i + k] - sum[i];
            right[i] = i;
        } else {
            right[i] = right[i + 1];
        }
    }
    dp[k - 1] = sum[k];
    for (i = k; i < n; i++) {
        dp[i] = dp[i - 1];
        if (sum[i + 1] - sum[i + 1 - k] + dp[left[i - 1]] > dp[i]) {
            dp[i] = sum[i + 1] - sum[i + 1 - k] + dp[left[i - 1]];
        }
    }
    max = 0;
    for (i = 2 * k - 1; i < n - k; i++) {
        if (sum[i + 1] - sum[i + 1 - k] + dp[i - 1] + sum[right[i + k]] - sum[right[i + k] - k] > max) {
            max = sum[i + 1] - sum[i + 1 - k] + dp[i - 1] + sum[right[i + k]] - sum[right[i + k] - k];
            ans[0] = left[i - k];
            ans[1] = i - k + 1;
            ans[2] = right[i + k];
        }
        }
        *returnSize = 3;
        free(sum);
        free(left);
        free(right);
        free(dp);
        return ans;
}   