/**https://leetcode.com/problems/knight-dialer/ */
//The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagram:
//A chess knight can move as indicated in the chess diagram below:
//We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
//Given an integer n, return how many distinct phone numbers of length n we can dial.
//You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.
//As the answer may be very large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 10
//Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
//Example 2:
//Input: n = 2
//Output: 20
//Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
//Example 3:
//Input: n = 3131
//Output: 136006598
//Explanation: Please take care of the mod.
// 
//Constraints:
//	1 <= n <= 5000
class Solution {
    public int knightDialer(int n) {
        int mod = 1000000007;
        long[][] dp = new long[n + 1][10];
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1; // Base case: one way to reach each digit in one step
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i - 1][4] + dp[i - 1][6]) % mod;
            dp[i][1] = (dp[i - 1][6] + dp[i - 1][8]) % mod;
            dp[i][2] = (dp[i - 1][7] + dp[i - 1][9]) % mod;
            dp[i][3] = (dp[i - 1][4] + dp[i - 1][8]) % mod;
            dp[i][4] = (dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][9]) % mod;
            dp[i][5] = 0; // No valid moves from digit '5'
            dp[i][6] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][7]) % mod;
            dp[i][7] = (dp[i - 1][2] + dp[i - 1][6]) % mod;
            dp[i][8] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][9] = (dp[i - 1][2] + dp[i - 1][4]) % mod;
        }
        long res = 0;
        for (int i = 0; i < 10; i++) {
            res = (res + dp[n][i]) % mod; // Sum all possible numbers of length n
        }
        return (int) res; // Return the result modulo 10^9 + 7    
    }
}