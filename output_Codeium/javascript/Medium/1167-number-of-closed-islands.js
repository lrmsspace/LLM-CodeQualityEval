/**https://leetcode.com/problems/number-of-closed-islands/ */
//Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
//Return the number of closed islands.
// 
//Example 1:
//Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
//Output: 2
//Explanation: 
//Islands in gray are closed because they are completely surrounded by water (group of 1s).
//Example 2:
//Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
//Output: 1
//Example 3:
//Input: grid = [[1,1,1,1,1,1,1],
//               [1,0,0,0,0,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,1,0,1,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,0,0,0,0,1],
//               [1,1,1,1,1,1,1]]
//Output: 2
// 
//Constraints:
//	1 <= grid.length, grid[0].length <= 100
//	0 <= grid[i][j] <=1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var closedIsland = function(grid) {
    let res = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (grid[i][j] === 0 && isClosed(grid, i, j)) {
                res++;
            }
        }
    }
    return res;

    function isClosed(grid, i, j) {
        if (i === 0 || i === grid.length - 1 || j === 0 || j === grid[0].length - 1) {
            return false;
        }
        if (grid[i][j] !== 0) {
            return true;
        }
        grid[i][j] = -1;
        const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
        for (const direction of directions) {
            const x = i + direction[0];
            const y = j + direction[1];
            if (!isClosed(grid, x, y)) {
                return false;
            }
        }
        return true;
    }
};