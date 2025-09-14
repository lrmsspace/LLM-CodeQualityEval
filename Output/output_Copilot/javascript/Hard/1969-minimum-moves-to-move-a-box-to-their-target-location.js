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
var minPushBox = function(grid) {
    const m = grid.length, n = grid[0].length;
    let start, target, box;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 'S') start = [i, j];
            else if (grid[i][j] === 'T') target = [i, j];
            else if (grid[i][j] === 'B') box = [i, j];
        }
    }

    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    
    function isValid(x, y) {
        return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] !== '#';
    }

    function bfs(start, box) {
        const queue = [[...start, ...box]];
        const visited = new Set();
        visited.add(start.join(',') + box.join(','));
        let pushes = 0;

        while (queue.length) {
            const size = queue.length;
            for (let i = 0; i < size; i++) {
                const [px, py, bx, by] = queue.shift();
                if (bx === target[0] && by === target[1]) return pushes;

                for (const [dx, dy] of directions) {
                    const nbx = bx + dx;
                    const nby = by + dy;
                    if (!isValid(nbx, nby) || visited.has([px, py].join(',') + [nbx, nby].join(','))) continue;

                    if (isValid(bx - dx, by - dy)) {
                        visited.add([px, py].join(',') + [nbx, nby].join(','));
                        queue.push([bx - dx, by - dy, nbx, nby]);
                    }
                }
            }
            pushes++;
        }
        return -1;
    }

    return bfs(start, box);    
};