/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.
// 
//Example 1:
//Input: grid = [[1,0],[0,1]]
//Output: 3
//Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
//Example 2:
//Input: grid = [[1,1],[1,0]]
//Output: 4
//Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
//Example 3:
//Input: grid = [[1,1],[1,1]]
//Output: 4
//Explanation: Can't change any 0 to 1, only one island with area = 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 500
//	grid[i][j] is either 0 or 1.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var largestIsland = function(grid) {
    const n = grid.length;
    const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    let islandSize = 0;
    const islandMap = new Map();
    
    function dfs(row, col) {
        if (row < 0 || row >= n || col < 0 || col >= n || grid[row][col] === 0 || islandMap.has([row, col])) {
            return 0;
        }
        
        islandMap.set([row, col], true);
        let size = 1;
        
        for (const [dr, dc] of directions) {
            size += dfs(row + dr, col + dc);
        }
        
        return size;
    }
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                islandSize = Math.max(islandSize, dfs(i, j));
            }
        }
    }
    
    return islandSize;
    
};