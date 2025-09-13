/**https://leetcode.com/problems/unique-paths-iii/ */
//You are given an m x n integer array grid where grid[i][j] could be:
//	1 representing the starting square. There is exactly one starting square.
//	2 representing the ending square. There is exactly one ending square.
//	0 representing empty squares we can walk over.
//	-1 representing obstacles that we cannot walk over.
//Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
// 
//Example 1:
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
//Output: 2
//Explanation: We have the following two paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
//2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
//Example 2:
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
//Output: 4
//Explanation: We have the following four paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
//2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
//3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
//4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
//Example 3:
//Input: grid = [[0,1],[2,0]]
//Output: 0
//Explanation: There is no path that walks over every empty square exactly once.
//Note that the starting and ending square can be anywhere in the grid.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	1 <= m * n <= 20
//	-1 <= grid[i][j] <= 2
//	There is exactly one starting cell and one ending cell.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var uniquePathsIII = function(grid) {
    let m = grid.length, n = grid[0].length;
    let total = 1, x = 0, y = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                total++;
            } else if (grid[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    }
    let res = 0;
    const dfs = (x, y, left) => {
        if (left == 0) {
            res++;
            return;
        }
        let directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
        for (let i = 0; i < 4; ++i) {
            let nx = x + directions[i][0], ny = y + directions[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                grid[nx][ny] = -1;
                dfs(nx, ny, left - 1);
                grid[nx][ny] = 0;
            }
        }
    };
    dfs(x, y, total);
    return res;
};