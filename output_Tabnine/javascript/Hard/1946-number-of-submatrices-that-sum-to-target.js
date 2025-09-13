/**https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/ */
//Given a matrix and a target, return the number of non-empty submatrices that sum to target.
//A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
//Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
// 
//Example 1:
//Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
//Output: 4
//Explanation: The four 1x1 submatrices that only contain 0.
//Example 2:
//Input: matrix = [[1,-1],[-1,1]], target = 0
//Output: 5
//Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
//Example 3:
//Input: matrix = [[904]], target = 0
//Output: 0
// 
//Constraints:
//	1 <= matrix.length <= 100
//	1 <= matrix[0].length <= 100
//	-1000 <= matrix[i][j] <= 1000
//	-10^8 <= target <= 10^8
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {number}
 */
var numSubmatrixSumTarget = function(matrix, target) {
    const m = matrix.length;
    const n = matrix[0].length;
    const dp = Array.from({ length: m + 1 }, () => Array.from({ length: n + 1 }, () => 0));
    let count = 0;
    
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }
    
    for (let left = 1; left <= n; left++) {
        for (let right = left; right <= n; right++) {
            const prefixSums = new Map();
            prefixSums.set(0, 1);
            let sum = 0;
            
            for (let i = 1; i <= m; i++) {
                sum += dp[i][right] - dp[i][left - 1];
                
                if (prefixSums.has(sum - target)) {
                    count += prefixSums.get(sum - target);
                }
                
                prefixSums.set(sum, (prefixSums.get(sum) || 0) + 1);
            }
        }
    }
    
    return count;
    
};