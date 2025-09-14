/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 9
//Example 2:
//Input: grid = [[1,1,0,0]]
//Output: 1
// 
//Constraints:
//	1 <= grid.length <= 100
//	1 <= grid[0].length <= 100
//	grid[i][j] is 0 or 1
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][][] dp = new int[n + 1][m + 1][2];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] == 1) {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                    for (int len = Math.min(dp[i][j][0], dp[i][j][1]); len > 0; len--) {
                        if (dp[i - len + 1][j][0] >= len && dp[i][j - len + 1][1] >= len) {
                            ans = Math.max(ans, len);
                            break;
                        }
                    }
                }
            }
        }
        return ans * ans;        
    }
}