/**https://leetcode.com/problems/diagonal-traverse/ */
//Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,4,7,5,3,6,8,9]
//Example 2:
//Input: mat = [[1,2],[3,4]]
//Output: [1,2,3,4]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	-105 <= mat[i][j] <= 105
/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var findDiagonalOrder = function(mat) {
if (mat.length === 0) return [];

const m = mat.length;
const n = mat[0].length;
const result = [];
let row = 0, col = 0, direction = 1;

for (let i = 0; i < m * n; i++) {
    result.push(mat[row][col]);
    row -= direction;
    col += direction;
    
    if (row >= m) { row = m - 1; col += 2; direction = -direction; }
    if (col >= n) { col = n - 1; row += 2; direction = -direction; }
    if (row < 0) { row = 0; direction = -direction; }
    if (col < 0) { col = 0; direction = -direction; }
}

return result;

};