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
    for(let i=0;i<grid.length-2;i++){
        for(let j=0;j<grid[0].length-2;j++){
            let sum = 0;
            let rowSum = 0;
            let colSum = 0;
            let diagSum = 0;
            let antiDiagSum = 0;
            let set = new Set();
            for(let k=0;k<3;k++){
                for(let l=0;l<3;l++){
                    sum += grid[i+k][j+l];
                    rowSum += grid[i+k][j+l];
                }
            }
        }
    }
    return count;
};