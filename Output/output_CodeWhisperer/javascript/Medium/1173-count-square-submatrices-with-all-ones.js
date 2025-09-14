/**https://leetcode.com/problems/count-square-submatrices-with-all-ones/ */
//Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
// 
//Example 1:
//Input: matrix =
//[
//  [0,1,1,1],
//  [1,1,1,1],
//  [0,1,1,1]
//]
//Output: 15
//Explanation: 
//There are 10 squares of side 1.
//There are 4 squares of side 2.
//There is  1 square of side 3.
//Total number of squares = 10 + 4 + 1 = 15.
//Example 2:
//Input: matrix = 
//[
//  [1,0,1],
//  [1,1,0],
//  [1,1,0]
//]
//Output: 7
//Explanation: 
//There are 6 squares of side 1.  
//There is 1 square of side 2. 
//Total number of squares = 6 + 1 = 7.
// 
//Constraints:
//	1 <= arr.length <= 300
//	1 <= arr[0].length <= 300
//	0 <= arr[i][j] <= 1
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var countSquares = function(matrix) {
    let m = matrix.length;
    let n = matrix[0].length;
    let dp = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let count = 0;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] == 1) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                count += dp[i][j];
            }
        }
    }
    return count;
};