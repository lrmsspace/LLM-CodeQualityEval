/**https://leetcode.com/problems/score-after-flipping-matrix/ */
//You are given an m x n binary matrix grid.
//A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
//Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
//Return the highest possible score after making any number of moves (including zero moves).
// 
//Example 1:
//Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
//Output: 39
//Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//Example 2:
//Input: grid = [[0]]
//Output: 1
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	grid[i][j] is either 0 or 1.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var matrixScore = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    let score = 0;
    
    // Flip rows and columns to make the first column all 1s
    for (let i = 0; i < m; i++) {
        if (grid[i][0] === 0) {
            for (let j = 0; j < n; j++) {
                grid[i][j] = grid[i][j] ^ 1;
            }
        }
    }
    
    // Calculate the score
    for (let i = 0; i < n; i++) {
        let onesCount = 0;
        for (let j = 0; j < m; j++) {
            onesCount += grid[j][i];
        }
        score += Math.pow(2, n - 1 - i) * Math.max(onesCount, m - onesCount);
    }
    
    return score;
    
};