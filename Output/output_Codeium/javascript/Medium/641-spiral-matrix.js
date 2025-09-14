/**https://leetcode.com/problems/spiral-matrix/ */
//Given an m x n matrix, return all elements of the matrix in spiral order.
// 
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,3,6,9,8,7,4,5]
//Example 2:
//Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//Output: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 10
//	-100 <= matrix[i][j] <= 100
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    const result = [];
    let rowStart = 0;
    let rowEnd = matrix.length - 1;
    let colStart = 0;
    let colEnd = matrix[0].length - 1;
    
    while (rowStart <= rowEnd && colStart <= colEnd) {
        for (let i = colStart; i <= colEnd; i++) {
            result.push(matrix[rowStart][i]);
        }
        rowStart++;
        for (let i = rowStart; i <= rowEnd; i++) {
            result.push(matrix[i][colEnd]);
        }
        colEnd--;
        if (rowStart <= rowEnd) {
            for (let i = colEnd; i >= colStart; i--) {
                result.push(matrix[rowEnd][i]);
            }
        }
        rowEnd--;
        if (colStart <= colEnd) {
            for (let i = rowEnd; i >= rowStart; i--) {
                result.push(matrix[i][colStart]);
            }
        }
        colStart++;
    }
    
    return result;
};