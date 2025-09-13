/**https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/ */
//Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
// 
//Example 1:
//Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
//Output: 2
//Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
//Example 2:
//Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
//Output: 0
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 300
//	0 <= mat[i][j] <= 104
//	0 <= threshold <= 105
/**
 * @param {number[][]} mat
 * @param {number} threshold
 * @return {number}
 */
var maxSideLength = function(mat, threshold) {
    let m = mat.length, n = mat[0].length, prefixSum = Array(m + 1).fill(0).map(() => Array(n + 1).fill(0)), sideLength = 0;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            let l = 1, r = Math.min(m, n) - i + 1, mid;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (prefixSum[i + mid - 1][j + mid - 1] - prefixSum[i + mid - 1][j - 1] - prefixSum[i - 1][j + mid - 1] + prefixSum[i - 1][j - 1] <= threshold) {
                    sideLength = Math.max(sideLength, mid);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
    }
    return sideLength;
};