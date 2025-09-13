/**https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/ */
//You have n dice, and each dice has k faces numbered from 1 to k.
//Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 1, k = 6, target = 3
//Output: 1
//Explanation: You throw one die with 6 faces.
//There is only one way to get a sum of 3.
//Example 2:
//Input: n = 2, k = 6, target = 7
//Output: 6
//Explanation: You throw two dice, each with 6 faces.
//There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
//Example 3:
//Input: n = 30, k = 30, target = 500
//Output: 222616187
//Explanation: The answer must be returned modulo 109 + 7.
// 
//Constraints:
//	1 <= n, k <= 30
//	1 <= target <= 1000
class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        int MOD = (int) 1e9 + 7;
        int[][] dp = new int[n + 1][target + 1];
        
        // Initialize the base cases
        for (int i = 1; i <= k; i++) {
            dp[1][i] = 1;
        }
        
        for (int dice = 2; dice <= n; dice++) {
            for (int sum = dice; sum <= target; sum++) {
                for (int face = 1; face <= k; face++) {
                    if (face <= sum - dice) {
                        dp[dice][sum] = (dp[dice][sum] + dp[dice - 1][sum - face]) % MOD;
                    }
                }
            }
        }
        
        return dp[n][target];
        
    }
}