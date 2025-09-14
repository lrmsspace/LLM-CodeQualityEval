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
    let count = 0;
    const magicSquares = [
        [8, 1, 6, 3, 5, 7, 4, 9, 2],
        [6, 1, 8, 7, 5, 3, 2, 9, 4],
        [4, 9, 2, 3, 5, 7, 8, 1, 6],
        [2, 9, 4, 7, 5, 3, 6, 1, 8],
        [8, 3, 4, 1, 5, 9, 6, 7, 2],
        [4, 3, 8, 9, 5, 1, 2, 7, 6],
        [6, 7, 2, 1, 5, 9, 8, 3, 4],
        [2, 7, 6, 9, 5, 1, 4, 3, 8]
    ];
    for (let i = 0; i < grid.length - 2; i++) {
        for (let j = 0; j < grid[i].length - 2; j++) {
            const subgrid = [].concat(grid[i].slice(j, j + 3), grid[i + 1].slice(j, j + 3), grid[i + 2].slice(j, j + 3));
            if (magicSquares.includes(subgrid.join(','))) {
                count++;
            }
        }
    }
    return count;
};