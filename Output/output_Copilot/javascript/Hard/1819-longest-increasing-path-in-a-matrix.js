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
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var longestIncreasingPath = function(matrix) {
    if (!matrix || matrix.length === 0 || matrix[0].length === 0) return 0;
    
    const rows = matrix.length;
    const cols = matrix[0].length;
    const dp = Array.from({ length: rows }, () => Array(cols).fill(0));
    
    let maxPath = 0;
    
    const directions = [
        [-1, 0], // up
        [1, 0],  // down
        [0, -1], // left
        [0, 1]   // right
    ];
    
    const dfs = (row, col) => {
        if (dp[row][col] !== 0) return dp[row][col];
        
        let maxLength = 1; // The cell itself counts as a path of length 1
        
        for (const [dx, dy] of directions) {
            const newRow = row + dx;
            const newCol = col + dy;
            
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[row][col]) {
                maxLength = Math.max(maxLength, 1 + dfs(newRow, newCol));
            }
        }
        
        dp[row][col] = maxLength;
        return maxLength;
    };
    
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            maxPath = Math.max(maxPath, dfs(i, j));
        }
    }
    
    return maxPath;    
};