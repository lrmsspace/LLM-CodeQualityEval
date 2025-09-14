/**https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/ */
//You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
//Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 12
//Explanation: There are 12 possible way to paint the grid as shown.
//Example 2:
//Input: n = 5000
//Output: 30228214
// 
//Constraints:
//	n == grid.length
//	1 <= n <= 5000
class Solution {
    public int numOfWays(int n) {
        int mod = 1000000007;
        long[][] dp = new long[n + 1][3];
        dp[1][0] = 6; // 6 ways to paint the first row with 3 colors
        dp[1][1] = 6; // 6 ways to paint the first row with 2 colors
        dp[1][2] = 0; // no way to paint the first row with 0 colors

        for (int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] * 2 + dp[i - 1][1]) % mod; // two adjacent cells can be painted with different colors
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % mod; // one adjacent cell can be painted with the same color
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod; // no adjacent cells can be painted with the same color
        }

        return (int) ((dp[n][0] + dp[n][1]) % mod); // return the total number of ways to paint the grid    
    }
}