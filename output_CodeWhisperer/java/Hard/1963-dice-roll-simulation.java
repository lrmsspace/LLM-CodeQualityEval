/**https://leetcode.com/problems/dice-roll-simulation/ */
//A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
//Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls. Since the answer may be too large, return it modulo 109 + 7.
//Two sequences are considered different if at least one element differs from each other.
// 
//Example 1:
//Input: n = 2, rollMax = [1,1,2,2,2,3]
//Output: 34
//Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
//Example 2:
//Input: n = 2, rollMax = [1,1,1,1,1,1]
//Output: 30
//Example 3:
//Input: n = 3, rollMax = [1,1,1,2,2,3]
//Output: 181
// 
//Constraints:
//	1 <= n <= 5000
//	rollMax.length == 6
//	1 <= rollMax[i] <= 15
class Solution {
    public int dieSimulator(int n, int[] rollMax) {
        int[][] dp = new int[n + 1][7];
        int[][] seq = new int[n + 1][7];
        int mod = (int)1e9 + 7;
        for (int i = 0; i <= 6; i++) {
            dp[1][i] = 1;
            seq[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= 6; j++) {
                for (int k = 1; k <= 6; k++) {
                    if (j == k) continue;
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    if (seq[i - 1][k] < rollMax[k - 1]) {
                        seq[i][j] = (seq[i][j] + seq[i - 1][k]) % mod;
                    }
                }
                dp[i][j] = (dp[i][j] + seq[i - 1][j] * (j == 0 ? 1 : dp[i - 1][0])) % mod;
            }
        }
        return (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5] + dp[n][6]) % mod;       
    }
}