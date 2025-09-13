/*
 There are an infinite amount of bags on a number line, one bag for each coordinate. Some of these bags contain coins.
 You are given a 2D array coins, where coins[i] = [li, ri, ci] denotes that every bag from li to ri contains ci coins.
 The segments that coins contain are non-overlapping.
 You are also given an integer k.
 Return the maximum amount of coins you can obtain by collecting k consecutive bags.
 Example 1:
 Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
 Output: 10
 Explanation:
 Selecting bags at positions [3, 4, 5, 6] gives the maximum number of coins: 2 + 0 + 4 + 4 = 10.
 Example 2:
 Input: coins = [[1,10,3]], k = 2
 Output: 6
 Explanation:
 Selecting bags at positions [1, 2] gives the maximum number of coins: 3 + 3 = 6.
 Constraints:
 1 <= coins.length <= 105
 1 <= k <= 109
 coins[i] == [li, ri, ci]
 1 <= li <= ri <= 109
 1 <= ci <= 1000
 The given segments are non-overlapping.
*/

class Solution {
    public long maximumCoins(int[][] coins, int k) {
        Arrays.sort(coins, (a, b) -> b[2] - a[2]); // Sort coins by coin value in descending order
        long[] dp = new long[k + 1]; // dp[i] represents the maximum amount of coins obtained by selecting i consecutive bags
        for (int i = 1; i <= k; i++) {
            dp[i] = coins[i - 1][2]; // Initialize dp[i] with the value of the first coin
            for (int j = i - 2; j >= 0 && coins[j][1] >= coins[i - 1][0]; j--) {
                dp[i] = Math.max(dp[i], dp[j] + coins[i - 1][2]); // Update dp[i] by considering all possible previous bags
            }
        }
        return dp[k]; // Return the maximum amount of coins obtained by selecting k consecutive bags
        
    }
}