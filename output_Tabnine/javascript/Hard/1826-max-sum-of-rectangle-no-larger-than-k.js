/**https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ */
//Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
//It is guaranteed that there will be a rectangle with a sum no larger than k.
// 
//Example 1:
//Input: matrix = [[1,0,1],[0,-2,3]], k = 2
//Output: 2
//Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
//Example 2:
//Input: matrix = [[2,2,-1]], k = 3
//Output: 3
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 100
//	-100 <= matrix[i][j] <= 100
//	-105 <= k <= 105
// 
//Follow up: What if the number of rows is much larger than the number of columns?
/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var maxSumSubmatrix = function(matrix, k) {
    const m = matrix.length;
    const n = matrix[0].length;
    let maxSum = Number.NEGATIVE_INFINITY;
    const prefixSum = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }
    
    for (let left = 1; left <= n; left++) {
        for (let right = left; right <= n; right++) {
            const sums = new Set();
            sums.add(0);
            let currentSum = 0;
            
            for (let top = 1; top <= m; top++) {
                currentSum += prefixSum[top][right] - prefixSum[top][left - 1];
                
                if (sums.has(currentSum - k)) {
                    maxSum = Math.max(maxSum, currentSum);
                }
                
                sums.add(currentSum);
            }
        }
    }
    
    return maxSum;
    

};