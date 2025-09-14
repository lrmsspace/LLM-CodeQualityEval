/**https://leetcode.com/problems/set-matrix-zeroes/ */
//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
//You must do it in place.
// 
//Example 1:
//Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
//Output: [[1,0,1],[0,0,0],[1,0,1]]
//Example 2:
//Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// 
//Constraints:
//	m == matrix.length
//	n == matrix[0].length
//	1 <= m, n <= 200
//	-231 <= matrix[i][j] <= 231 - 1
// 
//Follow up:
//	A straightforward solution using O(mn) space is probably a bad idea.
//	A simple improvement uses O(m + n) space, but still not the best solution.
//	Could you devise a constant space solution?
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    let firstRowHasZero = false;
    let firstColHasZero = false;
    
    // Mark the rows and columns that have zeros
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === 0) {
                if (i === 0) {
                    firstRowHasZero = true;
                }
                if (j === 0) {
                    firstColHasZero = true;
                }
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // Set the marked rows and columns to 0
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (matrix[0][j] === 0 || matrix[i][0] === 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set the first row and column to 0 if they had zeros
    if (firstRowHasZero) {
        for (let j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
    if (firstColHasZero) {
        for (let i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
};