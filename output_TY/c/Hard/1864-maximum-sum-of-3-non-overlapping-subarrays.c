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
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize){
    int i, j, kk, sum, maxSum, maxSum1, maxSum2, maxSum3, maxSum1Index, maxSum2Index, maxSum3Index, *result;
    result = (int *)malloc(sizeof(int) * 3);
    maxSum = 0;
    for (i = 0; i < numsSize - k; i++) {
        sum = 0;
        for (j = 0; j < k; j++) {
            sum += nums[i + j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxSum1Index = i;
            maxSum1 = maxSum;
        }
    }
    for (i = maxSum1Index + 1; i < numsSize - k; i++) {
        sum = 0;
    }
    for (j = 0; j < k; j++) {
        sum += nums[i + j];
    }
    if (sum > maxSum2) {
        maxSum2 = sum;
        maxSum2Index = i;
    }
    for (i = maxSum2Index + 1; i < numsSize - k; i++) {
        sum = 0;
        for (j = 0; j < k; j++) {
            sum += nums[i + j];
        }
        if (sum > maxSum3) {
            maxSum3 = sum;
            maxSum3Index = i;
        }
    }
    return maxSum1 + maxSum2 + maxSum3;
}