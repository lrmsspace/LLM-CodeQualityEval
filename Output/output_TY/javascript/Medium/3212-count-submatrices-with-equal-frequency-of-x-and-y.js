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
    let m = grid.length, n = grid[0].length;
    let preSum = Array.from({length: m}, () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            preSum[i][j] = grid[i][j];
            if (j > 0) preSum[i][j] += preSum[i][j - 1];
            if (i > 0) preSum[i][j] += preSum[i - 1][j];
            if (i > 0 && j > 0) preSum[i][j] -= preSum[i - 1][j - 1];
        }
    }
    let res = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = i; k < m; k++) {
                for (let l = j; l < n; l++) {
                    let sum = preSum[k][l];
                    if (j > 0) sum -= preSum[k][j - 1];
                    if (i > 0) sum -= preSum[i - 1][l];
                    if (i > 0 && j > 0) sum += preSum[i - 1][j - 1];
                    if (sum <= k) res++;
                }

            }
        }
    }
    return res;
    
};