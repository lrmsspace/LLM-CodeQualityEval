/**https://leetcode.com/problems/minimum-falling-path-sum/ */
//Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
//A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
// 
//Example 1:
//Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
//Output: 13
//Explanation: There are two falling paths with a minimum sum as shown.
//Example 2:
//Input: matrix = [[-19,57],[-40,-5]]
//Output: -59
//Explanation: The falling path with a minimum sum is shown.
// 
//Constraints:
//	n == matrix.length == matrix[i].length
//	1 <= n <= 100
//	-100 <= matrix[i][j] <= 100
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var minFallingPathSum = function(matrix) {
    let n = matrix.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        dp[0][i] = matrix[0][i];
    }
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < n; j++) {
            dp[i][j] = matrix[i][j] + Math.min(dp[i - 1][j], dp[i - 1][Math.max(0, j - 1)], dp[i - 1][Math.min(n - 1, j + 1)]);
        }
    }
    return Math.min(...dp[n - 1]);
};