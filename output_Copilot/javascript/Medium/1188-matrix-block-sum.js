/**https://leetcode.com/problems/matrix-block-sum/ */
//Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
//	i - k <= r <= i + k,
//	j - k <= c <= j + k, and
//	(r, c) is a valid position in the matrix.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//Output: [[12,21,16],[27,45,33],[24,39,28]]
//Example 2:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
//Output: [[45,45,45],[45,45,45],[45,45,45]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n, k <= 100
//	1 <= mat[i][j] <= 100
/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[][]}
 */
var matrixBlockSum = function(mat, k) {
    const m = mat.length, n = mat[0].length;
    const prefixSum = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    
    // Calculate prefix sums
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }
    
    const result = Array.from({ length: m }, () => Array(n).fill(0));
    
    // Calculate the block sum using the prefix sums
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const r1 = Math.max(0, i - k), c1 = Math.max(0, j - k);
            const r2 = Math.min(m - 1, i + k), c2 = Math.min(n - 1, j + k);
            result[i][j] = prefixSum[r2 + 1][c2 + 1] - prefixSum[r2 + 1][c1] - prefixSum[r1][c2 + 1] + prefixSum[r1][c1];
        }
    }
    
    return result;  
};