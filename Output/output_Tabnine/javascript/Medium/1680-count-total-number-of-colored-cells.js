/**https://leetcode.com/problems/count-total-number-of-colored-cells/ */
//There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:
//	At the first minute, color any arbitrary unit cell blue.
//	Every minute thereafter, color blue every uncolored cell that touches a blue cell.
//Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.
//Return the number of colored cells at the end of n minutes.
// 
//Example 1:
//Input: n = 1
//Output: 1
//Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
//Example 2:
//Input: n = 2
//Output: 5
//Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5. 
// 
//Constraints:
//	1 <= n <= 105
/**
 * @param {number} n
 * @return {number}
 */
var coloredCells = function(n) {
    // Initialize the grid with no cells colored
    let grid = Array(n).fill().map(() => Array(n).fill(false));
    
    // Initialize the boundary cells to be colored
    for (let i = 0; i < n; i++) {
        grid[0][i] = grid[n - 1][i] = true;
        grid[i][0] = grid[i][n - 1] = true;
    }
    
    // Start coloring the cells
    let coloredCells = 4; // Count the boundary cells
    for (let i = 1; i < n; i++) {
        for (let j = 1; j < n; j++) {
            if (!grid[i][j]) {
                // Check if the cell touches a blue cell
                let touchingBlue = false;
                for (let k = -1; k <= 1; k++) {
                    for (let l = -1; l <= 1; l++) {
                        if (k === 0 && l === 0) continue;
                        if (grid[i + k][j + l]) {
                            touchingBlue = true;
                            break;
                        }
                    }
                }
                if (touchingBlue) {
                    grid[i][j] = true;
                    coloredCells++;
                }
            }
        }
    }
    
    return coloredCells;
    
};