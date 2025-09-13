/**https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/ */
//Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
//A grid is said to be valid if all the cells above the main diagonal are zeros.
//Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
//The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
// 
//Example 1:
//Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
//Output: 3
//Example 2:
//Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
//Output: -1
//Explanation: All rows are similar, swaps have no effect on the grid.
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
//Output: 0
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 200
//	grid[i][j] is either 0 or 1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minSwaps = function(grid) {
    const n = grid.length;
    let swaps = 0;
    
    // Find the first row with an odd number of 1s
    let row = -1;
    for (let i = 0; i < n; i++) {
        let count = 0;
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                count++;
            }
        }
        if (count % 2 === 1) {
            row = i;
            break;
        }
    }
    
    if (row === -1) {
        return 0;
    }
    
    // Find the index of the first 1 in the row
    let firstOne = -1;
    for (let j = 0; j < n; j++) {
        if (grid[row][j] === 1) {
            firstOne = j;
            break;
        }
    }
    
    // Find the index of the first 0 in the row (from the right)
    let firstZero = n;
    for (let j = n - 1; j >= 0; j--) {
        if (grid[row][j] === 0) {
            firstZero = j;
            break;
        }
    }
    
    // Swap the first 1 with the first 0 in the row
    grid[row][firstOne] = 0;
    grid[row][firstZero] = 1;
    swaps++;
    
    // Update the grid and count the number of swaps needed for the remaining rows
    for (let i = row + 1; i < n; i++) {
        let count = 0;
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                count++;
            }
        }
        if (count % 2 === 1) {
            return -1;
        }
        
        let firstOne = -1;
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                firstOne = j;
                break;
            }
        }
        
        let firstZero = n;
        for (let j = n - 1; j >= 0; j--) {
            if (grid[i][j] === 0) {
                firstZero = j;
                break;
            }
        }
        
        grid[i][firstOne] = 0;
        grid[i][firstZero] = 1;
        swaps++;
    }
    
    return swaps;
    
};