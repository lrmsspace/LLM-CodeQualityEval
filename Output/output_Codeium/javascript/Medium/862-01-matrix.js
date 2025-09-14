/**https://leetcode.com/problems/01-matrix/ */
//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//The distance between two adjacent cells is 1.
// 
//Example 1:
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
//Example 2:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	mat[i][j] is either 0 or 1.
//	There is at least one 0 in mat.
/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var updateMatrix = function(mat) {
    let m = mat.length;
    let n = mat[0].length;
    let result = Array(m).fill(0).map(() => Array(n).fill(Infinity));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j] === 0) {
                result[i][j] = 0;
            }
        }
    }
    let directions = [[-1,0], [1,0], [0,-1], [0,1]];
    let queue = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j] === 0) {
                queue.push([i, j]);
            }
        }
    }
    while (queue.length > 0) {
        let [i, j] = queue.shift();
        for (let direction of directions) {
            let ni = i + direction[0];
            let nj = j + direction[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && result[ni][nj] > result[i][j] + 1) {
                result[ni][nj] = result[i][j] + 1;
                queue.push([ni, nj]);
            }
        }
    }
    return result;
    
};