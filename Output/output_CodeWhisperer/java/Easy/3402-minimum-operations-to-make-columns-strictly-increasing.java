/*
 You are given a m x n matrix grid consisting of non-negative integers.
 In one operation, you can increment the value of any grid[i][j] by 1.
 Return the minimum number of operations needed to make all columns of grid strictly increasing.
 Example 1:
 Input: grid = [[3,2],[1,3],[3,4],[0,1]]
 Output: 15
 Explanation:
 To make the 0th column strictly increasing, we can apply 3 operations on grid[1][0], 2 operations on grid[2][0], and 6 operations on grid[3][0].
 To make the 1st column strictly increasing, we can apply 4 operations on grid[3][1].
 Example 2:
 Input: grid = [[3,2,1],[2,1,0],[1,2,3]]
 Output: 12
 Explanation:
 To make the 0th column strictly increasing, we can apply 2 operations on grid[1][0], and 4 operations on grid[2][0].
 To make the 1st column strictly increasing, we can apply 2 operations on grid[1][1], and 2 operations on grid[2][1].
 To make the 2nd column strictly increasing, we can apply 2 operations on grid[1][2].
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m, n <= 50
 0 <= grid[i][j] < 2500
*/

class Solution {
    public int minimumOperations(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[n][m];
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count = 0;
                for (int k = 0; k < m; k++) {
                    if (grid[k][i] < grid[j][i]) {
                        count = Math.max(count, dp[i][k]);
                    }
                }
                dp[i][j] = count + 1;
                max = Math.max(max, dp[i][j]);
            }
        }
        return n * m - max;        
    }
}