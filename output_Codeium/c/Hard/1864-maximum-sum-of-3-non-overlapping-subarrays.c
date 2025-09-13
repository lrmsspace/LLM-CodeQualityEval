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
    int prefix_sum[numsSize + 1];
    prefix_sum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }
    int dp[numsSize + 1][4] = { {0} };
    for (int i = 1; i <= numsSize; i++) {
        for (int j = 1; j <= 3; j++) {
            int sum = prefix_sum[i] - prefix_sum[i - k];
            if (sum > dp[i - 1][j - 1]) {
                dp[i][j] = sum + dp[i - k][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int* result = malloc(3 * sizeof(int));
    int i = numsSize, j = 3;
    while (j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            result[j - 1] = i - k;
            i -= k;
            j--;
        } else {
            i--;
        }
    }
    *returnSize = 3;
    return result;
}