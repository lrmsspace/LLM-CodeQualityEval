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
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int[] dp = new int[n + 1];
        int[] left = new int[n + 1];
        for (int i = k; i <= n; i++) {
            if (prefixSum[i] - prefixSum[i - k] > dp[i - k]) {
                dp[i] = prefixSum[i] - prefixSum[i - k];
                left[i] = i - k;
            } else {
                dp[i] = dp[i - k];
                left[i] = left[i - k];
            }
        }

        int[] result = new int[3];
        int maxSum = 0;
        for (int j = 2 * k; j <= n; j++) {
            if (dp[j] + dp[left[j]] > maxSum) {
                maxSum = dp[j] + dp[left[j]];
                result[0] = left[left[j]];
                result[1] = left[j];
                result[2] = j - k;
            }
        }
        return result;        
    }
}