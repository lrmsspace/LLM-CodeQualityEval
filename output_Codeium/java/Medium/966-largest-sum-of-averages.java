/**https://leetcode.com/problems/largest-sum-of-averages/ */
//You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.
//Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
//Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.
// 
//Example 1:
//Input: nums = [9,1,2,3,9], k = 3
//Output: 20.00000
//Explanation: 
//The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
//We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
//That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
//Example 2:
//Input: nums = [1,2,3,4,5,6,7], k = 4
//Output: 20.50000
// 
//Constraints:
//	1 <= nums.length <= 100
//	1 <= nums[i] <= 104
//	1 <= k <= nums.length
class Solution {
    public double largestSumOfAverages(int[] nums, int k) {
        double[] prefixSum = new double[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        double[][] dp = new double[nums.length][k + 1];
        for (int i = 0; i < nums.length; i++) {
            dp[i][1] = prefixSum[i + 1] / (i + 1);
        }
        for (int j = 2; j <= k; j++) {
            for (int i = j - 1; i < nums.length; i++) {
                for (int m = j - 2; m < i; m++) {
                    dp[i][j] = Math.max(dp[i][j], dp[m][j - 1] + (prefixSum[i + 1] - prefixSum[m + 1]) / (i - m));
                }
            }
        }
        return dp[nums.length - 1][k];
    }
}