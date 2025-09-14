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
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int* prefixSum = (int*)malloc(sizeof(int) * numsSize);
    prefixSum[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    
    int maxSum = INT_MIN;
    for (int i = k - 1; i < numsSize - 2 * k + 1; i++) {
        int sum = prefixSum[i + k - 1] - (i >= k? prefixSum[i - k] : 0);
        if (sum > maxSum) {
            maxSum = sum;
            dp[i] = sum;
        }
    }
    
    int* left = (int*)malloc(sizeof(int) * (numsSize - 2 * k + 1));
    left[0] = 0;
    int maxLeft = 0;
    for (int i = 1; i < numsSize - 2 * k + 1; i++) {
        if (dp[i] > dp[maxLeft]) {
            maxLeft = i;
        }
        left[i] = maxLeft;
    }
    
    int* right = (int*)malloc(sizeof(int) * (numsSize - 2 * k + 1));
    right[numsSize - 2 * k] = numsSize - 1;
    int maxRight = numsSize - 2 * k;
    for (int i = numsSize - 2 * k - 1; i >= 0; i--) {
        if (dp[i] > dp[maxRight]) {
            maxRight = i;
        }
        right[i] = maxRight;
    }
    
    int* result = (int*)malloc(sizeof(int) * 3);
    int maxIndex = 0;
    for (int i = k; i < numsSize - 2 * k; i++) {
        if (left[i - k] < left[maxIndex] || (left[i - k] == left[maxIndex] && right[i + k] > right[maxIndex])) {
            maxIndex = i;
        }
    }
    
    result[0] = left[maxIndex];
    result[1] = maxIndex + k;
    result[2] = right[maxIndex];
    *returnSize = 3;
    
    free(dp);
    free(prefixSum);
    free(left);
    free(right);
    
    return result;
}