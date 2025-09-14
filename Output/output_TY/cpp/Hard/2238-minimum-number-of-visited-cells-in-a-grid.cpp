/**https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/ */
//You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0).
//Starting from the cell (i, j), you can move to one of the following cells:
//	Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
//	Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
//Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.
// 
//Example 1:
//Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
//Output: 4
//Explanation: The image above shows one of the paths that visits exactly 4 cells.
//Example 2:
//Input: grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
//Output: 3
//Explanation: The image above shows one of the paths that visits exactly 3 cells.
//Example 3:
//Input: grid = [[2,1,0],[1,0,0]]
//Output: -1
//Explanation: It can be proven that no path exists.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	0 <= grid[i][j] < m * n
//	grid[m - 1][n - 1] == 0
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int k = min(j + grid[i][j], n - 1);
                for(; j <= k; j++){
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
                k = min(i + grid[i][j], m - 1);
            }
        }
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                int k = min(i + grid[i][j], m - 1);
                for(; i <= k; i++){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }
        return dp[m - 1][n - 1] == INT_MAX ? -1 : dp[m - 1][n - 1];
    }
};