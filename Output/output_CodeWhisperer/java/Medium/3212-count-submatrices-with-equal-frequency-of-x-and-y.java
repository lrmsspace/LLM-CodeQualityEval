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
        int count = 0;
        int[][] dp = new int[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid[0].length;j++) {
                if(grid[i][j] == 'X') {
                    dp[i][j] = 1;
                    if(i>0) {
                        dp[i][j] += dp[i-1][j];
                    }
                    if(j>0) {
                        dp[i][j] += dp[i][j-1];
                    }
                    if(i>0 && j>0) {
                        dp[i][j] -= dp[i-1][j-1];
                    }
                    count += dp[i][j];
                }
            }
        }
        return count;
                
    }
}