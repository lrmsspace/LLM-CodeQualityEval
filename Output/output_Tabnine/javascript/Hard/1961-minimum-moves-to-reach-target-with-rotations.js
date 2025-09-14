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
    const moves = [[0, 1], [1, 0], [0, -1], [-1, 0]]; // right, down, left, up
    const directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]; // clockwise, counterclockwise
    
    const queue = [[[0, 0, 0], 0]]; // [x, y, rotation]
    
    const visited = new Set();
    visited.add(JSON.stringify([0, 0, 0]));
    
    while (queue.length > 0) {
        const [x, y, rotation] = queue.shift();
        
        if (x === n - 1 && y === n - 2) {
            return rotation;
        }
        
        for (let i = 0; i < 4; i++) {
            const nx = x + moves[i][0];
            const ny = y + moves[i][1];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] === 0 &&!visited.has(JSON.stringify([nx, ny, (rotation + i) % 4]))) {
                visited.add(JSON.stringify([nx, ny, (rotation + i) % 4]));
                queue.push([nx, ny, (rotation + i) % 4]);
            }
        }
        
        for (let i = 0; i < 2; i++) {
            const nx = x + directions[i][0];
            const ny = y + directions[i][1];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] === 0 &&!visited.has(JSON.stringify([nx, ny, (rotation + 2 + i) % 4]))) {
                visited.add(JSON.stringify([nx, ny, (rotation + 2 + i) % 4]));
                queue.push([nx, ny, (rotation + 2 + i) % 4]);
            }
        }

    }
    
    return -1;
    
};