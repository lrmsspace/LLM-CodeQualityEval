/**https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/ */
//You are given an m x n integer matrix mat and an integer target.
//Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.
//Return the minimum absolute difference.
//The absolute difference between two numbers a and b is the absolute value of a - b.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
//Output: 0
//Explanation: One possible choice is to:
//- Choose 1 from the first row.
//- Choose 5 from the second row.
//- Choose 7 from the third row.
//The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.
//Example 2:
//Input: mat = [[1],[2],[3]], target = 100
//Output: 94
//Explanation: The best possible choice is to:
//- Choose 1 from the first row.
//- Choose 2 from the second row.
//- Choose 3 from the third row.
//The sum of the chosen elements is 6, and the absolute difference is 94.
//Example 3:
//Input: mat = [[1,2,9,8,7]], target = 6
//Output: 1
//Explanation: The best choice is to choose 7 from the first row.
//The absolute difference is 1.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 70
//	1 <= mat[i][j] <= 70
//	1 <= target <= 800
/**
 * @param {number[][]} mat
 * @param {number} target
 * @return {number}
 */
var minimizeTheDifference = function(mat, target) {
    const m = mat.length;
    const n = mat[0].length;
    const dp = Array.from({ length: m }, () => Array(n).fill(Infinity));
    
    // Initialize the first row
    for (let j = 0; j < n; j++) {
        dp[0][j] = Math.abs(mat[0][j] - target);
    }
    
    // Build up the dp table
    for (let i = 1; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < n; k++) {
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + Math.abs(mat[i][j] - target));
            }
        }
    }
    
    // Return the minimum absolute difference
    return Math.min(...dp[m - 1]);
    
};