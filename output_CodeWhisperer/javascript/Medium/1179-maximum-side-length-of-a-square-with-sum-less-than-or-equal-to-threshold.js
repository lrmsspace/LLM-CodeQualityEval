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
    const m = mat.length;
    const n = mat[0].length;
    
    // Create prefix sum matrix
    const prefix = Array(m + 1).fill(0).map(() => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mat[i-1][j-1];
        }
    }
    
    // Function to check if we can form a square with side length k
    const isValid = (k) => {
        for (let i = k; i <= m; i++) {
            for (let j = k; j <= n; j++) {
                const sum = prefix[i][j] - prefix[i-k][j] - prefix[i][j-k] + prefix[i-k][j-k];
                if (sum <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // Binary search for the maximum valid side length
    let left = 0, right = Math.min(m, n);
    while (left < right) {
        const mid = Math.floor((left + right + 1) / 2);
        if (isValid(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
};
