/*
 You are given a 2D matrix grid consisting of positive integers.
 You have to select one or more cells from the matrix such that the following conditions are satisfied:
 No two selected cells are in the same row of the matrix.
 The values in the set of selected cells are unique.
 Your score will be the sum of the values of the selected cells.
 Return the maximum score you can achieve.
 Example 1:
 Input: grid = [[1,2,3],[4,3,2],[1,1,1]]
 Output: 8
 Explanation:
 We can select the cells with values 1, 3, and 4 that are colored above.
 Example 2:
 Input: grid = [[8,7,6],[8,3,2]]
 Output: 15
 Explanation:
 We can select the cells with values 7 and 8 that are colored above.
 Constraints:
 1 <= grid.length, grid[i].length <= 10
 1 <= grid[i][j] <= 100
*/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxScore = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const selected = new Set();
    let maxScore = 0;

    const backtrack = (r, c, currentScore) => {
        if (r === rows) {
            maxScore = Math.max(maxScore, currentScore);
            return;
        }
        if (c === cols) {
            backtrack(r + 1, 0, currentScore);
            return;
        }

        const cellValue = grid[r][c];
        if (!selected.has(cellValue)) {
            selected.add(cellValue);
            backtrack(r, c + 1, currentScore + cellValue);
            selected.delete(cellValue);
        }
        backtrack(r, c + 1, currentScore);
    };

    backtrack(0, 0, 0);
    return maxScore;
};