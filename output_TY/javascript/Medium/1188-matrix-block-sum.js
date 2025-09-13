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
    let m = mat.length;
    let n = mat[0].length;
    let dp = new Array(m+1).fill(0).map(()=>new Array(n+1).fill(0));
    for(let i=1;i<=m;i++){
        for(let j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1];
        }
    }
    let ans = new Array(m).fill(0).map(()=>new Array(n).fill(0));
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            let x1 = Math.max(1,i-k);
            let y1 = Math.max(1,j-k);
            let x2 = Math.min(m,i+k+1);
            let y2 = Math.min(n,j+k+1);
            ans[i][j] = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
        }
    }
    return ans;
};