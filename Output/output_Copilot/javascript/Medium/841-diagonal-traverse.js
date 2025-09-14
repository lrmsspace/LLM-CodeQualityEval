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
    let m = mat.length, n = mat[0].length;
    let result = [];
    for (let d = 0; d < m + n - 1; d++) {
        let r = d < n ? 0 : d - n + 1;
        let c = d < n ? d : n - 1;
        while (r < m && c >= 0) {
            result.push(mat[r][c]);
            r++;
            c--;
        }
    }
    return result;    
};