/**https://leetcode.com/problems/constrained-subsequence-sum/ */
//Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
//A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.
// 
//Example 1:
//Input: nums = [10,2,-10,5,20], k = 2
//Output: 37
//Explanation: The subsequence is [10, 2, 5, 20].
//Example 2:
//Input: nums = [-1,-2,-3], k = 1
//Output: -1
//Explanation: The subsequence must be non-empty, so we choose the largest number.
//Example 3:
//Input: nums = [10,-2,-10,-5,20], k = 2
//Output: 23
//Explanation: The subsequence is [10, -2, -5, 20].
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	-104 <= nums[i] <= 104
int constrainedSubsetSum(int* nums, int numsSize, int k) {
    int dp[numsSize];
    dp[0] = nums[0];
    int max_sum = dp[0];

    for (int i = 1; i < numsSize; i++) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        if (i - k - 1 >= 0) {
            dp[i] = max(dp[i], dp[i - k - 1] + nums[i]);
        }
        max_sum = max(max_sum, dp[i]);
    }

    return max_sum;
}
