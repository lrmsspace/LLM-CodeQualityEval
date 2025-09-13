/*
 Given a 0-indexed m x n integer matrix matrix, create a new 0-indexed matrix called answer. Make answer equal to matrix, then replace each element with the value -1 with the maximum element in its respective column.
 Return the matrix answer.
 Example 1:
 Input: matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
 Output: [[1,2,9],[4,8,6],[7,8,9]]
 Explanation: The diagram above shows the elements that are changed (in blue).
 - We replace the value in the cell [1][1] with the maximum value in the column 1, that is 8.
 - We replace the value in the cell [0][2] with the maximum value in the column 2, that is 9.
 Example 2:
 Input: matrix = [[3,-1],[5,2]]
 Output: [[3,2],[5,2]]
 Explanation: The diagram above shows the elements that are changed (in blue).
 Constraints:
 m == matrix.length
 n == matrix[i].length
 2 <= m, n <= 50
 -1 <= matrix[i][j] <= 100
 The input is generated such that each column contains at least one non-negative integer.
*/

/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var modifiedMatrix = function(matrix) {
    let m = matrix.length, n = matrix[0].length;
    let sum = new Array(m).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (j > 0) sum[i][j] += sum[i][j - 1];
            if (i > 0) sum[i][j] += sum[i - 1][j];
            if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
            sum[i][j] += matrix[i][j];
        }
    }
    let ans = -1;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let x1 = i, y1 = j, x2 = m - 1, y2 = n - 1;
            if (i > 0) x1 = i - 1;
            if (j > 0) y1 = j - 1;
            if (i < m - 1) x2 = i + 1;
            if (j < n - 1) y2 = j + 1;
            let s = sum[x2][y2];
            if (i > 0) s -= sum[x1 - 1][y2];
        }
    }
    return ans;
    
};