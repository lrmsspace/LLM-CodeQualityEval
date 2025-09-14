/**https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */
//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
// 
//Example 1:
//Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
//Output: 4
//Explanation: The longest increasing path is [1, 2, 6, 9].
//Example 2:
//Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
//Output: 4
//Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//Example 3:
//Input: matrix = [[1]]
//Output: 1
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 200
//	0 <= matrix[i][j] <= 231 - 1    
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Memoization table to store the length of the longest path starting from each cell
        vector<vector<int>> memo(m, vector<int>(n, 0));
        
        // Direction vectors for the four possible moves (up, right, down, left)
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        int maxLength = 0;
        
        // Try starting from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLength = max(maxLength, dfs(matrix, memo, i, j, m, n, dx, dy));
            }
        }
        
        return maxLength;
    }
    
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j, int m, int n, 
            vector<int>& dx, vector<int>& dy) {
        // If we've already computed the result for this cell, return it
        if (memo[i][j] > 0) return memo[i][j];
        
        // Initialize the length to 1 (the cell itself)
        memo[i][j] = 1;
        
        // Try all four directions
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            // Check if the new position is valid and the value is greater
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                // Update the length if we find a longer path
                memo[i][j] = max(memo[i][j], 1 + dfs(matrix, memo, ni, nj, m, n, dx, dy));
            }
        }
        
        return memo[i][j];
    }
};
