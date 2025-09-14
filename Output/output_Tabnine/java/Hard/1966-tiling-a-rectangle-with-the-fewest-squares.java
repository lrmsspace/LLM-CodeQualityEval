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
        int[][] dp = new int[n + 1][m + 1];
        int maxSide = (int) Math.sqrt(Math.min(n, m));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int side = 1; side <= maxSide && side <= i && side <= j; side++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - side][j] + dp[side][j] + 1);
                }
            }
        }
        return dp[n][m];
    }
}