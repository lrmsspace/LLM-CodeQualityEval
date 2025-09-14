/*
 Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
 grid[0][0]
 an equal frequency of 'X' and 'Y'.
 at least one 'X'.
 Example 1:
 Input: grid = [["X","Y","."],["Y",".","."]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [["X","X"],["X","Y"]]
 Output: 0
 Explanation:
 No submatrix has an equal frequency of 'X' and 'Y'.
 Example 3:
 Input: grid = [[".","."],[".","."]]
 Output: 0
 Explanation:
 No submatrix has at least one 'X'.
 Constraints:
 1 <= grid.length, grid[i].length <= 1000
 grid[i][j] is either 'X', 'Y', or '.'.
*/

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numberOfSubmatrices = function(grid) {
    let count = 0;
    let row = grid.length;
    let col = grid[0].length;
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (grid[i][j] === 'X') {
                let xCount = 0;
                let yCount = 0;
                for (let k = i; k < row; k++) {
                    for (let l = j; l < col; l++) {
                        if (grid[k][l] === 'X') {
                            xCount++;
                        } else if (grid[k][l] === 'Y') {
                            yCount++;
                        }
                    }
                }
                if (xCount === yCount && xCount > 0) {
                    count++;
                }
            }
        }
    }
    return count;
};