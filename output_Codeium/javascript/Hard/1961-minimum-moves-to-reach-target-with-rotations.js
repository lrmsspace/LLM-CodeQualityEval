/**https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/ */
//In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
//In one move the snake can:
//	Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//	Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//	Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).
//	
//	Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).
//	
//Return the minimum number of moves to reach the target.
//If there is no way to reach the target, return -1.
// 
//Example 1:
//Input: grid = [[0,0,0,0,0,1],
//               [1,1,0,0,1,0],
//               [0,0,0,0,1,1],
//               [0,0,1,0,1,0],
//               [0,1,1,0,0,0],
//               [0,1,1,0,0,0]]
//Output: 11
//Explanation:
//One possible solution is [right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down].
//Example 2:
//Input: grid = [[0,0,1,1,1,1],
//               [0,0,0,0,1,1],
//               [1,1,0,0,0,1],
//               [1,1,1,0,0,1],
//               [1,1,1,0,0,1],
//               [1,1,1,0,0,0]]
//Output: 9
// 
//Constraints:
//	2 <= n <= 100
//	0 <= grid[i][j] <= 1
//	It is guaranteed that the snake starts at empty cells.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumMoves = function(grid) {
    let n = grid.length;
    let directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    let queue = [[0, 0, 1, 0, 0]];
    let visited = [[[0, 0, 0], [0, 1, 0]]];
    let step = 0;

    while (queue.length > 0) {
        let size = queue.length;
        for (let i = 0; i < size; i++) {
            let [x1, y1, x2, y2, dir] = queue.shift();
            if (x1 == n - 1 && y1 == n - 2 || x2 == n - 1 && y2 == n - 1) {
                return step;
            }
            for (let j = 0; j < 4; j++) {
                if (j == dir) {
                    continue;
                }
                let [nx1, ny1] = [x1 + directions[j][0], y1 + directions[j][1]];
                let [nx2, ny2] = [x2 + directions[j][0], y2 + directions[j][1]];
                if (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < n && nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < n && grid[nx1][ny1] == 0 && grid[nx2][ny2] == 0 && !visited.some(v => v[0][0] == nx1 && v[0][1] == ny1 && v[1][0] == nx2 && v[1][1] == ny2)) {
                    queue.push([nx1, ny1, nx2, ny2, j]);
                    visited.push([[nx1, ny1], [nx2, ny2]]);
                }
            }
        }
        step++;
    }
    return -1;
};