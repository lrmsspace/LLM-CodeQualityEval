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
    let startX, startY, endX, endY, emptyCount = 0;
    const m = grid.length, n = grid[0].length;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                startX = i;
                startY = j;
            } else if (grid[i][j] === 2) {
                endX = i;
                endY = j;
            } else if (grid[i][j] === 0) {
                emptyCount++;
            }
        }
    }

    const dfs = (x, y, count) => {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] === -1) return 0;
        if (x === endX && y === endY) return count === emptyCount ? 1 : 0;

        const temp = grid[x][y];
        grid[x][y] = -1; // mark as visited
        let paths = dfs(x + 1, y, count + (temp === 0 ? 1 : 0)) +
                   dfs(x - 1, y, count + (temp === 0 ? 1 : 0)) +
                   dfs(x, y + 1, count + (temp === 0 ? 1 : 0)) +
                   dfs(x, y - 1, count + (temp === 0 ? 1 : 0));
        grid[x][y] = temp; // unmark

        return paths;
    };

    return dfs(startX, startY, -1); // start with -1 to include the starting square    
};