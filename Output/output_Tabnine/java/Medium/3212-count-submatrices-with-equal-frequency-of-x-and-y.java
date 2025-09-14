/*
 Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
 grid[0][0]
 an equal frequency of 'X' and 'Y'.
 at least one 'X'.
 Example 1:
 Input: grid = [["X","Y","."],["Y",".","."]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [["X","X"],["X","Y"]]
 Output: 0
 Explanation:
 No submatrix has an equal frequency of 'X' and 'Y'.
 Example 3:
 Input: grid = [[".","."],[".","."]]
 Output: 0
 Explanation:
 No submatrix has at least one 'X'.
 Constraints:
 1 <= grid.length, grid[i].length <= 1000
 grid[i][j] is either 'X', 'Y', or '.'.
*/

class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m + 1][n + 1];
        int count = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i - 1][j - 1] == 'X') {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + 1;
                }
            }
            for (int j = 1; j <= n; j++) {
                for (int k = j; k <= n; k++) {
                    count += dp[i][k] - dp[i][j - 1];
                }
            }
            count -= dp[i][n] * (n - 1);
            if (count > 0) {
                return count;
            }
            count = 0;
            for (int j = 1; j <= m; j++) {
                for (int k = j; k <= m; k++) {
                    count += dp[k][n] - dp[j - 1][n];
                }
            }
            count -= dp[m][n] * (m - 1);
            if (count > 0) {
                return count;
            }
            count = 0;  
            for (int j = 1; j <= n; j++) {
                for (int k = j; k <= n; k++) {
                    count += dp[m][k] - dp[m][j - 1];
                }
            }
            count -= dp[m][n] * (n - 1);
            if (count > 0) {
                return count;
            }
            count = 0;
            for (int j = 1; j <= m; j++) {
                for (int k = j; k <= m; k++) {
                    count += dp[k][n] - dp[j - 1][n];
                }
            }
            count -= dp[m][n] * (m - 1);



            if (count > 0) {
                return count;
            }
        }
        return 0;
        
    }
}