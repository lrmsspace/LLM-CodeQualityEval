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
    int* result = (int*)malloc(sizeof(int) * 3);
    *returnSize = 3;
    int maxSum = 0;
    int left = 0;
    int mid = k;
    int right = 2 * k;
    int leftSum = 0;
    int midSum = 0;
    int rightSum = 0;
    for (int i = 0; i < k; i++) {
        leftSum += nums[i];
        midSum += nums[i + k];
        rightSum += nums[i + 2 * k];
    }
    maxSum = leftSum + midSum + rightSum;
    while (right < numsSize) {
        leftSum = leftSum - nums[left] + nums[left + k];
        midSum = midSum - nums[mid] + nums[mid + k];
        rightSum = rightSum - nums[right] + nums[right + k];
        if (leftSum > maxSum) {
            maxSum = leftSum;
            left = left + k;
            mid = mid + k;
            right = right + k;
        }
        else if (midSum > maxSum) {
            maxSum = midSum;
            left = left + k;
            mid = mid + k;
            right = right + k;
        }
        else if (rightSum > maxSum) {
            maxSum = rightSum;
            left = left + k;
            mid = mid + k;
            right = right + k;
        }
        else {
            left++;
            mid++;
            right++;
        }
    }
    result[0] = left;
    result[1] = mid;
    result[2] = right;
    return result;
    
}