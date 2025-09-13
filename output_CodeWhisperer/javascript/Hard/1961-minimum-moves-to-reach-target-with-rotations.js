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
    let queue = [[0, 1, 0]]; // [row, col, direction] direction: 0 = horizontal, 1 = vertical
    let visited = new Set(["0,1,0"]);
    let steps = 0;
    while (queue.length > 0) {
        let next = [];
        for (let i = 0; i < queue.length; i++) {
            let [r, c, d] = queue[i];
            if (r == n - 1 && c == n - 2 && d == 0) return steps;
            if (d == 0) {
                if (c + 1 < n && grid[r][c + 1] == 0) {
                    let key = `${r},${c + 1},0`;
                    if (!visited.has(key)) {
                        visited.add(key);
                        next.push([r, c + 1, 0]);
                    }
                    if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0) {
                        let key = `${r},${c},1`;
                        if (!visited.has(key)) {
                            visited.add(key);
                            next.push([r, c, 1]);
                        }
                    }
                }
            } else {
                if (r + 1 < n && grid[r + 1][c] == 0) {
                    let key = `${r + 1},${c},1`;
                    if (!visited.has(key)) {
                        visited.add(key);
                        next.push([r + 1, c, 1]);
                    }
                    if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0) {
                        let key = `${r},${c},0`;
                        if (!visited.has(key)) {
                            visited.add(key);
                            next.push([r, c, 0]);
                        }
                    }
                }
            }
        }
        queue = next;
        steps++;
    }
    return -1;
};