/*
 You are given a 2D matrix grid of size 3 x 3 consisting only of characters 'B' and 'W'. Character 'W' represents the white color, and character 'B' represents the black color.
 Your task is to change the color of at most one cell so that the matrix has a 2 x 2 square where all cells are of the same color.
 Return true if it is possible to create a 2 x 2 square of the same color, otherwise, return false.
 Example 1:
 Input: grid = [["B","W","B"],["B","W","W"],["B","W","B"]]
 Output: true
 Explanation:
 It can be done by changing the color of the grid[0][2].
 Example 2:
 Input: grid = [["B","W","B"],["W","B","W"],["B","W","B"]]
 Output: false
 Explanation:
 It cannot be done by changing at most one cell.
 Example 3:
 Input: grid = [["B","W","B"],["B","W","W"],["B","W","W"]]
 Output: true
 Explanation:
 The grid already contains a 2 x 2 square of the same color.
 Constraints:
 grid.length == 3
 grid[i].length == 3
 grid[i][j] is either 'W' or 'B'.
*/

/**
 * @param {character[][]} grid
 * @return {boolean}
 */
var canMakeSquare = function(grid) {
    const n = grid.length;
    let sum = 0;
    let minLen = Infinity;
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 'W') {
                sum++;
            }
            minLen = Math.min(minLen, grid[i].length);
        }
    }
    
    if (sum % 4!== 0 || minLen < 2) {
        return false;
    }
    
    const target = sum / 4;
    let count = 0;
    let sumRow = 0; 
    let sumCol = 0;     
    let row = 0;
    let col = 0;    

    while (row < n) {
        while (count < target && col < n) {
            if (grid[row][col] === 'W') {
                sumRow++;
                sumCol++;
                count++;
            }
            col++;
        }
        
        if (count === target) {
            if (sumRow === target && sumCol === target) {
                return true;
            }
            sumRow = 0;
            sumCol = 0;
            count = 0;
        } else {
            row++;
            col = 0;
        }
    }
    
    return false;  // If no 2x2 square can be formed, return false.

    
};