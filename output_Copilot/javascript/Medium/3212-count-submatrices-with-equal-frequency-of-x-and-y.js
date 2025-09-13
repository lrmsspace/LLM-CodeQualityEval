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
    const m = grid.length;
    const n = grid[0].length;
    let count = 0;

    for (let r1 = 0; r1 < m; r1++) {
        for (let r2 = r1; r2 < m; r2++) {
            const freq = new Map();
            let xCount = 0, yCount = 0;

            for (let c = 0; c < n; c++) {
                let submatrixXCount = 0, submatrixYCount = 0;

                for (let r = r1; r <= r2; r++) {
                    if (grid[r][c] === 'X') {
                        submatrixXCount++;
                    } else if (grid[r][c] === 'Y') {
                        submatrixYCount++;
                    }
                }

                xCount += submatrixXCount;
                yCount += submatrixYCount;

                if (xCount > 0 && xCount === yCount) {
                    count++;
                }
            }
        }
    }

    return count;
        
};