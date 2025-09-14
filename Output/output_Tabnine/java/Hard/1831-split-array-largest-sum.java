/**https://leetcode.com/problems/split-array-largest-sum/ */
//Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
//Return the minimized largest sum of the split.
//A subarray is a contiguous part of the array.
// 
//Example 1:
//Input: nums = [7,2,5,10,8], k = 2
//Output: 18
//Explanation: There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
//Example 2:
//Input: nums = [1,2,3,4,5], k = 2
//Output: 9
//Explanation: There are four ways to split nums into two subarrays.
//The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	0 <= nums[i] <= 106
//	1 <= k <= min(50, nums.length)
class Solution {
    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        int[][] dp = new int[k][n];
        for (int i = 0; i < k; i++) {
            dp[i][i] = 0;
        }
        
        for (int len = 2; len <= n; len++) {
            for (int start = 0; start <= n - len; start++) {
                int end = start + len - 1;
                dp[0][end] = Math.max(dp[0][end], prefixSum[end + 1] - prefixSum[start]);
                for (int i = 1; i < k && i < end - start; i++) {
                    dp[i][end] = Math.min(dp[i][end], Math.max(dp[i - 1][start + i - 1], prefixSum[end + 1] - prefixSum[start]));
                }
            }
        }
        
        return dp[k - 1][n - 1];
        
    }
}