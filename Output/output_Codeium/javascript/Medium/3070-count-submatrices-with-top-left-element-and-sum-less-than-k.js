/*
 You are given a 0-indexed integer matrix grid and an integer k.
 Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
 Example 1:
 Input: grid = [[7,6,3],[6,6,1]], k = 18
 Output: 4
 Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
 Example 2:
 Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
 Output: 6
 Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
 Constraints:
 m == grid.length 
 n == grid[i].length
 1 <= n, m <= 1000 
 0 <= grid[i][j] <= 1000
 1 <= k <= 109
*/

/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var countSubmatrices = function(grid, k) {
    let count = 0;
    const rows = grid.length;
    const cols = grid[0].length;

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let sum = 0;
            for (let x = i; x < rows; x++) {
                for (let y = j; y < cols; y++) {
                    sum += grid[x][y];
                }
            }
            if (sum <= k) {
                count++;
            }
        }
    }

    return count;
};