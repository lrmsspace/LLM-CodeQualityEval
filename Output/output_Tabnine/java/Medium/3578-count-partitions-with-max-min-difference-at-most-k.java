/*
 You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.
 Return the total number of ways to partition nums under this condition.
 Since the answer may be too large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [9,4,1,3,7], k = 4
 Output: 6
 Explanation:
 There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:
 [[9], [4], [1], [3], [7]]
 [[9], [4], [1], [3, 7]]
 [[9], [4], [1, 3], [7]]
 [[9], [4, 1], [3], [7]]
 [[9], [4, 1], [3, 7]]
 [[9], [4, 1, 3], [7]]
 Example 2:
 Input: nums = [3,3,4], k = 0
 Output: 2
 Explanation:
 There are 2 valid partitions that satisfy the given conditions:
 [[3], [3], [4]]
 [[3, 3], [4]]
 Constraints:
 2 <= nums.length <= 5 * 104
 1 <= nums[i] <= 109
 0 <= k <= 109
*/

class Solution {
    public int countPartitions(int[] nums, int k) {
        int MOD = (int) (1e9 + 7);
        int n = nums.length;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int[][] dp = new int[n + 1][sum + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]) % MOD;
            }
        }
        int maxSum = sum / 2;

        int[][][] count = new int[n + 1][maxSum + 1][k + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= maxSum; j++) {
                for (int diff = 0; diff <= k; diff++) {
                    count[i][j][diff] = count[i - 1][j][diff];
                    if (j >= nums[i - 1] && diff >= nums[i - 1] - nums[0]) {
                        count[i][j][diff] = (count[i][j][diff] + count[i - 1][j - nums[i - 1]][diff - nums[i - 1] + nums[0]]) % MOD;
                    }
                }
            }
        }   
        return count[n][maxSum][k];
        
    }
}