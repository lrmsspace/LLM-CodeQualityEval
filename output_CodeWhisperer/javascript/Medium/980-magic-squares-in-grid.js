/**https://leetcode.com/problems/magic-squares-in-grid/ */
//A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
//Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
// 
//Example 1:
//Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
//Output: 1
//Explanation: 
//The following subgrid is a 3 x 3 magic square:
//while this one is not:
//In total, there is only one magic square inside the given grid.
//Example 2:
//Input: grid = [[8]]
//Output: 0
// 
//Constraints:
//	row == grid.length
//	col == grid[i].length
//	1 <= row, col <= 10
//	0 <= grid[i][j] <= 15
/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let ans = 0;
    for (let i = 0; i < m - 2; i++) {
        for (let j = 0; j < n - 2; j++) {
            if (grid[i + 1][j + 1] != 5) continue;
            if (new Set([grid[i][j], grid[i][j + 1], grid[i][j + 2], grid[i + 1][j], grid[i + 1][j + 2], grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]].filter(x => x > 0 && x <= 9).length) === 9) {
                let sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                if (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] == sum
                    && grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == sum
                    && grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == sum
                    && grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] == sum
                    && grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] == sum
                    && grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == sum
                    && grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] == sum) {
                    ans++;
                }
            }
        }
    }
    return ans;
};