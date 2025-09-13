/*
 You are given an integer array nums of length n.
 A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:
 Left subarray contains indices [0, i].
 Right subarray contains indices [i + 1, n - 1].
 Return the number of partitions where the difference between the sum of the left and right subarrays is even.
 Example 1:
 Input: nums = [10,10,3,7,6]
 Output: 4
 Explanation:
 The 4 partitions are:
 [10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
 [10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
 [10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
 [10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.
 Example 2:
 Input: nums = [1,2,2]
 Output: 0
 Explanation:
 No partition results in an even sum difference.
 Example 3:
 Input: nums = [2,4,6,8]
 Output: 3
 Explanation:
 All partitions result in an even sum difference.
 Constraints:
 2 <= n == nums.length <= 100
 1 <= nums[i] <= 100
*/

class Solution {
    public int countPartitions(int[] nums) {
        int n = nums.length;
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int[][] dp = new int[n][totalSum + 1];
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        
        for (int sum = 0; sum <= totalSum; sum++) {
            dp[0][sum] = sum % 2 == 0? 1 : 0;
            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= sum; j++) {
                    dp[i][j] = dp[i - 1][j] + (j >= nums[i]? dp[i - 1][j - nums[i]] : 0);
                }
            }
            if (dp[n - 1][sum] == 1) {
                return (totalSum - sum) / 2;
            }
            if (dp[n - 1][sum] == 2) {
                return (totalSum - sum) / 2 + 1;
            }
            if (dp[n - 1][sum] == 3) {
                return (totalSum - sum) / 2 + 2;
            }
            if (dp[n - 1][sum] == 4) {
                return (totalSum - sum) / 2 + 3;
            }
            if (dp[n - 1][sum] == 5) {
                return (totalSum - sum) / 2 + 4;
            }
            if (dp[n - 1][sum] == 6) {
                return (totalSum - sum) / 2 + 5;
            }
            if (dp[n - 1][sum] == 7) {
                return (totalSum - sum) / 2 + 6;
            }   

            if (dp[n - 1][sum] == 8) {
                return (totalSum - sum) / 2 + 7;
            }
        }
        return 0;   
        
    }
}