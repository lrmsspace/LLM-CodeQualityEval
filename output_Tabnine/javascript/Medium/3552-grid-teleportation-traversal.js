/*
 You are given a 2D character grid matrix of size m x n, represented as an array of strings, where matrix[i][j] represents the cell at the intersection of the ith row and jth column. Each cell is one of the following:
 '.' representing an empty cell.
 '#' representing an obstacle.
 An uppercase letter ('A'-'Z') representing a teleportation portal.
 You start at the top-left cell (0, 0), and your goal is to reach the bottom-right cell (m - 1, n - 1). You can move from the current cell to any adjacent cell (up, down, left, right) as long as the destination cell is within the grid bounds and is not an obstacle.
 If you step on a cell containing a portal letter and you haven't used that portal letter before, you may instantly teleport to any other cell in the grid with the same letter. This teleportation does not count as a move, but each portal letter can be used at most once during your journey.
 Return the minimum number of moves required to reach the bottom-right cell. If it is not possible to reach the destination, return -1.
 Example 1:
 Input: matrix = ["A..",".A.","..."]
 Output: 2
 Explanation:
 Before the first move, teleport from (0, 0) to (1, 1).
 In the first move, move from (1, 1) to (1, 2).
 In the second move, move from (1, 2) to (2, 2).
 Example 2:
 Input: matrix = [".#...",".#.#.",".#.#.","...#."]
 Output: 13
 Explanation:
 Constraints:
 1 <= m == matrix.length <= 103
 1 <= n == matrix[i].length <= 103
 matrix[i][j] is either '#', '.', or an uppercase English letter.
 matrix[0][0] is not an obstacle.
*/

/**
 * @param {string[]} matrix
 * @return {number}
 */
var minMoves = function(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const visited = Array.from({ length: m }, () => Array(n).fill(false));
    const portalMap = new Map();
    let portalCount = 0;
    let minMoves = Infinity;
    
    // Find the portal cells and their destinations
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z') {
                portalMap.set(matrix[i][j], [i, j]);
                portalCount++;
            }
        }
    }
    if (portalCount === 0) {
        // No portals, just move from the top-left to the bottom-right
        return (m - 1) + (n - 1);
    }   
    
    // Perform breadth-first search to find the minimum number of moves
    const queue = [[0, 0, 0]]; // [row, col, moves]
    while (queue.length > 0) {  
        const [row, col, moves] = queue.shift();
        
        if (row === m - 1 && col === n - 1) {
            minMoves = Math.min(minMoves, moves);
            continue;

            // Mark the current cell as visited
        }   
        visited[row][col] = true;
        // Move up  
        if (row > 0 && matrix[row - 1][col]!== '#' &&!visited[row - 1][col]) {
            queue.push([row - 1, col, moves + 1]);
        }
        // Move down
        if (row < m - 1 && matrix[row + 1][col]!== '#' &&!visited[row + 1][col]) {
            queue.push([row + 1, col, moves + 1]);
        }
        // Move left
        if (col > 0 && matrix[row][col - 1]!== '#' &&!visited[row][col - 1]) {
            queue.push([row, col - 1, moves + 1]);
        }   
        // Move right
        if (col < n - 1 && matrix[row][col + 1]!== '#' &&!visited[row][col + 1]) {
            queue.push([row, col + 1, moves + 1]);
        }
        
        // If there are portals and the current cell is a portal, teleport to the destination
        if (portalMap.has(matrix[row][col])) {
            const [destRow, destCol] = portalMap.get(matrix[row][col]);
            queue.push([destRow, destCol, moves + 1]);
        }
    }   
    return minMoves === Infinity? -1 : minMoves;
    
};