/*
 You are given an m x n binary matrix grid.
 A row or column is considered palindromic if its values read the same forward and backward.
 You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
 Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4.
 Example 1:
 Input: grid = [[1,0,0],[0,1,0],[0,0,1]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [[0,1],[0,1],[0,0]]
 Output: 2
 Explanation:
 Example 3:
 Input: grid = [[1],[1]]
 Output: 2
 Explanation:
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m * n <= 2 * 105
 0 <= grid[i][j] <= 1
*/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minFlips = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    let flipCount = 0;
    let oneCount = 0;
    
    // Count the number of 1's and flip the first row if necessary
    for (let j = 0; j < n; j++) {
        oneCount += grid[0][j];
        if (oneCount % 2 === 1) {
            flipCount++;
            grid[0][j] = 1 - grid[0][j];
        }
    }
    
    // Check if the first row is already palindromic
    let isPalindrome = true;
    for (let j = 0; j < n; j++) {
        if (grid[0][j]!== grid[m - 1][n - 1 - j]) {
            isPalindrome = false;
            break;
        }
    }
    if (!isPalindrome) {
        flipCount++;
    }   
    
    // Check the remaining rows and columns
    for (let i = 1; i < m; i++) {
        // Count the number of 1's in the current row
        oneCount = 0;
        for (let j = 0; j < n; j++) {
            oneCount += grid[i][j];
            
            // Flip the current cell if necessary
            if (oneCount % 2 === 1) {
                flipCount++;
                grid[i][j] = 1 - grid[i][j];
            }
        }
        
        // Check if the current row is already palindromic
        isPalindrome = true;
        for (let j = 0; j < n; j++) {
            if (grid[i][j]!== grid[m - 1][n - 1 - j]) {
                isPalindrome = false;
                break;
            }
        }
        if (!isPalindrome) {
            flipCount++;
        }
        
        // Flip the current row with the first row if necessary 
        if (oneCount % 2 === 1) {
            for (let j = 0; j < n; j++) {
                grid[0][j] = 1 - grid[0][j];
            }
            flipCount++;
        }
    }

    return flipCount;
    
};