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
    let m = matrix.length;
    let n = matrix[0].length;
    let dp = new Array(m).fill(0).map(() => new Array(n).fill(0));
    let max = 0;
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            max = Math.max(max, dfs(i, j));
        }
    }
    return max;
    
    function dfs(i, j){
        if(dp[i][j] !== 0) return dp[i][j];
        let max = 0;
        for(let [x, y] of [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]){
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]){
                max = Math.max(max, dfs(x, y));
            }
}
    }
    return dp[i][j] = max + 1;
};