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
    let n = grid.length;
    let m = grid[0].length;
    let max = 0;
    let color = 2;
    let map = new Map();
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid[i][j] === 1) {
                let area = dfs(grid, i, j, color);
                map.set(color, area);
                max = Math.max(max, area);
                color++;
            }
        }
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid[i][j] === 0) {
                let set = new Set();
                if (i > 0) set.add(grid[i - 1][j]);
                if (i < n - 1) set.add(grid[i + 1][j]);
                if (j > 0) set.add(grid[i][j - 1]);
                if (j < m - 1) set.add(grid[i][j + 1]);
                let area = 1;
                for (let color of set) {
                    area += map.get(color);
                }
                max = Math.max(max, area);
            }
        }
    }
    return max;
 
};