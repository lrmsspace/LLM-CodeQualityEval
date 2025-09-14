/**https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/ */
//A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
//The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
//Your task is to move the box 'B' to the target position 'T' under the following rules:
//	The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
//	The character '.' represents the floor which means a free cell to walk.
//	The character '#' represents the wall which means an obstacle (impossible to walk there).
//	There is only one box 'B' and one target cell 'T' in the grid.
//	The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
//	The player cannot walk through the box.
//Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.
// 
//Example 1:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#",".","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 3
//Explanation: We return only the number of times the box is pushed.
//Example 2:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#","#","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: -1
//Example 3:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T",".",".","#","#"],
//               ["#",".","#","B",".","#"],
//               ["#",".",".",".",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 5
//Explanation: push the box down, left, left, up and up.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	grid contains only characters '.', '#', 'S', 'T', or 'B'.
//	There is only one character 'S', 'B', and 'T' in the grid.
/**
 * @param {character[][]} grid
 * @return {number}
 */
var minPushBox = function(grid) 
{
    let m = grid.length, n = grid[0].length;
    let sx = 0, sy = 0, bx = 0, by = 0;
    for (let i = 0; i < m; i++)
    {
        for (let j = 0; j < n; j++)
        {
            if (grid[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (grid[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }
    let queue = [];
    let visited = new Set();
    queue.push([bx, by, sx, sy]);
    visited.add(bx + "," + by + "," + sx + "," + sy);
    let dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]];
    let steps = 0;
    while (queue.length > 0)
    {
        let size = queue.length;
        for (let i = 0; i < size; i++)
        {
            let cur = queue.shift();
            let bx = cur[0], by = cur[1], sx = cur[2], sy = cur[3];
            if (grid[bx][by] == 'T') return steps;
            for (let dir of dirs)
            {
                let nbx = bx + dir[0], nby = by + dir[1];
                let nsx = bx - dir[0], nsy = by - dir[1];
                if (nbx < 0 || nbx >= m || nby < 0 || nby >= n || grid[nbx][nby] == '#') continue;
                if (nsx < 0 || nsx >= m || nsy < 0 || nsy >= n || grid[nsx][nsy] == '#') continue;
                if (visited.has(nbx + "," + nby + "," + bx + "," + by)) continue;
                if (sx == nsx && sy == nsy)
                {
                    queue.push([nbx, nby, bx, by]);
                    visited.add(nbx + "," + nby + "," + bx + "," + by);
                }
            }
        }
        steps++;
    }
    return -1;
};