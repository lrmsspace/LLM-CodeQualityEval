/**https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/ */
//You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
//The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
//In one day, we are allowed to change any single land cell (1) into a water cell (0).
//Return the minimum number of days to disconnect the grid.
// 
//Example 1:
//Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
//Output: 2
//Explanation: We need at least 2 days to get a disconnected grid.
//Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
//Example 2:
//Input: grid = [[1,1]]
//Output: 2
//Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 30
//	grid[i][j] is either 0 or 1.
class Solution {
    public int minDays(int[][] grid) {
        int n = grid.length;
        if(n == 0) return 0;
        int m = grid[0].length;
        int[][] dp = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    if(i == 0 && j == 0) dp[i][j] = 1;
                    else if(i == 0) dp[i][j] = dp[i][j-1] + 1;
                    else if(j == 0) dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }   
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(grid[i][j] == 1){
                    if(i == n-1 && j == m-1) dp[i][j] = 1;
                    else if(i == n-1) dp[i][j] = dp[i][j+1] + 1;
                    else if(j == m-1) dp[i][j] = dp[i+1][j] + 1;
                    else dp[i][j] = Math.min(dp[i][j+1], dp[i+1][j]) + 1;
                }
            }
        }
        return dp[0][0];
    }
}