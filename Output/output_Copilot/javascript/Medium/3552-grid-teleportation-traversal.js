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
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    const portals = new Map();
    const visited = new Set();
    let queue = [[0, 0, 0]]; // [row, col, moves]

    // Collect portals
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const cell = matrix[i][j];
            if (cell >= 'A' && cell <= 'Z') {
                if (!portals.has(cell)) {
                    portals.set(cell, []);
                }
                portals.get(cell).push([i, j]);
            }
        }
    }

    while (queue.length > 0) {
        const [row, col, moves] = queue.shift();

        // Check if we reached the bottom-right corner
        if (row === m - 1 && col === n - 1) {
            return moves;
        }

        // Explore adjacent cells
        for (const [dr, dc] of directions) {
            const newRow = row + dr;
            const newCol = col + dc;

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                matrix[newRow][newCol] !== '#' && !visited.has(`${newRow},${newCol}`)) {
                visited.add(`${newRow},${newCol}`);
                queue.push([newRow, newCol, moves + 1]);
            }
        }

        // Check for teleportation
        const portalCell = matrix[row][col];
        if (portalCell >= 'A' && portalCell <= 'Z') {
            for (const [pr, pc] of portals.get(portalCell)) {
                if (!visited.has(`${pr},${pc}`)) {
                    visited.add(`${pr},${pc}`);
                    queue.push([pr, pc, moves]); // No move cost for teleportation
                }
            }
            portals.delete(portalCell); // Use the portal only once
        }
    }

    return -1; // If we exhaust the queue without reaching the destination
        
};