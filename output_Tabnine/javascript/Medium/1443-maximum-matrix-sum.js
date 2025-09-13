/**https://leetcode.com/problems/maximum-matrix-sum/ */
//You are given an n x n integer matrix. You can do the following operation any number of times:
//	Choose any two adjacent elements of matrix and multiply each of them by -1.
//Two elements are considered adjacent if and only if they share a border.
//Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
// 
//Example 1:
//Input: matrix = [[1,-1],[-1,1]]
//Output: 4
//Explanation: We can follow the following steps to reach sum equals 4:
//- Multiply the 2 elements in the first row by -1.
//- Multiply the 2 elements in the first column by -1.
//Example 2:
//Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
//Output: 16
//Explanation: We can follow the following step to reach sum equals 16:
//- Multiply the 2 last elements in the second row by -1.
// 
//Constraints:
//	n == matrix.length == matrix[i].length
//	2 <= n <= 250
//	-105 <= matrix[i][j] <= 105
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function(matrix) {
    const n = matrix.length;
    let minSum = Number.MAX_SAFE_INTEGER;
    for (let i = 0; i < (1 << n); i++) {
        let rowSum = 0;
        let colSum = Array(n).fill(0);
        for (let j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) {
                rowSum += matrix[j][0];
                colSum[j] += matrix[0][j];
            }
        }
        minSum = Math.min(minSum, Math.max(...rowSum, Math.max(...colSum)));
    }
    return minSum * -2; // multiply by -2 because we used -1 in our operations
    
};