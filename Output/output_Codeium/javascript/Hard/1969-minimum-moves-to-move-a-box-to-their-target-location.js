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
    let m = grid.length;
    let n = grid[0].length;
    let dir = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    let sb = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 'S') sb.push([i, j]);
            if (grid[i][j] === 'B') sb.push([i, j]);
        }
    }
    let bfs = (sx, sy, bx, by, tx, ty) => {
        let q = [[sx, sy, bx, by, 0]];
        let visited = [[[sx, sy, bx, by]]];
        while (q.length > 0) {
            let [x, y, bx, by, step] = q.shift();
            if (bx === tx && by === ty) return step;
            for (let i = 0; i < 4; i++) {
                let nx = x + dir[i][0];
                let ny = y + dir[i][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] === '#') continue;
                if (nx === bx && ny === by) {
                    let nbx = bx + dir[i][0];
                    let nby = by + dir[i][1];
                    if (nbx < 0 || nbx >= m || nby < 0 || nby >= n || grid[nbx][nby] === '#') continue;
                }
                let found = false;
                for (let j = 0; j < visited.length; j++) {
                    if (visited[j][0][0] === nx && visited[j][0][1] === ny && visited[j][1][0] === bx && visited[j][1][1] === by) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    q.push([nx, ny, bx, by, step + 1]);
                    visited.push([[nx, ny], [bx, by]]);
                }
            }
        }
        return -1;
    };
    let res = bfs(sb[0][0], sb[0][1], sb[1][0], sb[1][1], sb[2][0], sb[2][1]);
    return res;
    
};