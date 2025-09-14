/**https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/ */
//Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
//Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
//A binary matrix is a matrix with all cells equal to 0 or 1 only.
//A zero matrix is a matrix with all cells equal to 0.
// 
//Example 1:
//Input: mat = [[0,0],[0,1]]
//Output: 3
//Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
//Example 2:
//Input: mat = [[0]]
//Output: 0
//Explanation: Given matrix is a zero matrix. We do not need to change it.
//Example 3:
//Input: mat = [[1,0,0],[1,0,0]]
//Output: -1
//Explanation: Given matrix cannot be a zero matrix.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 3
//	mat[i][j] is either 0 or 1.
/**
 * @param {number[][]} mat
 * @return {number}
 */
var minFlips = function(mat) {
    let m = mat.length;
    let n = mat[0].length;
    let ans = Number.MAX_SAFE_INTEGER;
    let dp = new Array(m).fill(0).map(() => new Array(n).fill(0));
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            dp[i][j] = mat[i][j];
        }
    }
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            let flip = 0;
            for(let k = 0; k < n; k++) {
                if(k !== j) {
                    flip += dp[i][k];
                }
            }
        }
    }
    return -1;
};