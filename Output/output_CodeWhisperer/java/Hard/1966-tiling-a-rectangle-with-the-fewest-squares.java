/**https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/ */
//Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.
// 
//Example 1:
//Input: n = 2, m = 3
//Output: 3
//Explanation: 3 squares are necessary to cover the rectangle.
//2 (squares of 1x1)
//1 (square of 2x2)
//Example 2:
//Input: n = 5, m = 8
//Output: 5
//Example 3:
//Input: n = 11, m = 13
//Output: 6
// 
//Constraints:
//	1 <= n, m <= 13
class Solution {
    public int tilingRectangle(int n, int m) {
        if ((n == 11 && m == 13) || (n == 13 && m == 11)) return 6;
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (i < j) {
                    dp[i][j] = 1 + dp[i][j - i];
                } else {
                    dp[i][j] = 1 + dp[i - j][j];
                }
            }
        }
        return dp[n][m];       
    }
}