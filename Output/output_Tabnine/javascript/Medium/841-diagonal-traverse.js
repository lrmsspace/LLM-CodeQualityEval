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
    const m = mat.length;
    const n = mat[0].length;
    const res = [];
    const dir = [[-1, 1], [1, -1]];
    
    for (let i = 0; i < m + n - 1; i++) {
        let x = 0;
        let y = i % 2 === 0? 0 : n - 1;
        while (x >= 0 && x < m && y >= 0 && y < n) {
            res.push(mat[x][y]);
            x += dir[i % 2][0];
            y += dir[i % 2][1];
        }
    }
    
    return res;
    
};