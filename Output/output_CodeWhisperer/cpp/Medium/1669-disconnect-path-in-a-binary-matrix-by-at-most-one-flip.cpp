/**https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/ */
//You are given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) that has the value 1. The matrix is disconnected if there is no path from (0, 0) to (m - 1, n - 1).
//You can flip the value of at most one (possibly none) cell. You cannot flip the cells (0, 0) and (m - 1, n - 1).
//Return true if it is possible to make the matrix disconnect or false otherwise.
//Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,0],[1,1,1]]
//Output: true
//Explanation: We can change the cell shown in the diagram above. There is no path from (0, 0) to (2, 2) in the resulting grid.
//Example 2:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: false
//Explanation: It is not possible to change at most one cell such that there is not path from (0, 0) to (2, 2).
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 1000
//	1 <= m * n <= 105
//	grid[i][j] is either 0 or 1.
//	grid[0][0] == grid[m - 1][n - 1] == 1
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (i > 0) dp[i][j] |= dp[i - 1][j];
                if (j > 0) dp[i][j] |= dp[i][j - 1];
            }
        }
        vector<vector<int>> dp2(m, vector<int>(n, 0));
        dp2[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) continue;
                if (i < m - 1) dp2[i][j] |= dp2[i + 1][j];
                if (j < n - 1) dp2[i][j] |= dp2[i][j + 1];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (i == 0 && j == 0) continue;
                if (i == m - 1 && j == n - 1) continue;
                if (dp[i][j] && dp2[i][j]) return true;
            }
        }
        return false;     
    }
};