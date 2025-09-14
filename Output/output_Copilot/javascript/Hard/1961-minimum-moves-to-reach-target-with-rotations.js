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
    const n = grid.length;
    const queue = [[0, 0, 0]]; // [row, col, direction]
    const visited = new Set();
    visited.add('0,0,0');
    const directions = [[1, 0], [0, 1]]; // down, right
    let moves = 0;

    while (queue.length) {
        const size = queue.length;
        for (let i = 0; i < size; i++) {
            const [row, col, dir] = queue.shift();
            if (row === n - 1 && col === n - 2) return moves;

            for (const [dx, dy] of directions) {
                const newRow = row + dx;
                const newCol = col + dy;
                if (newRow < n && newCol < n && grid[newRow][newCol] === 0) {
                    const newState = `${newRow},${newCol},${dir}`;
                    if (!visited.has(newState)) {
                        visited.add(newState);
                        queue.push([newRow, newCol, dir]);
                    }
                }
            }

            if (dir === 0 && row + 1 < n && grid[row + 1][col] === 0) { // rotate clockwise
                const newState = `${row},${col},1`;
                if (!visited.has(newState)) {
                    visited.add(newState);
                    queue.push([row, col, 1]);
                }
            } else if (dir === 1 && col + 1 < n && grid[row][col + 1] === 0) { // rotate counterclockwise
                const newState = `${row},${col},0`;
                if (!visited.has(newState)) {
                    visited.add(newState);
                    queue.push([row, col, 0]);
                }
            }
        }
        moves++;
    }

    return -1;    
};