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
class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] prefixSum = new int[m + 1][n + 1];
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = mat[i - 1][j - 1] 
                                + prefixSum[i - 1][j] 
                                + prefixSum[i][j - 1] 
                                - prefixSum[i - 1][j - 1];
            }
        }
        
        int left = 0, right = Math.min(m, n);
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (isSquareWithSumLessThanOrEqualToThreshold(prefixSum, mid, threshold)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    
    private boolean isSquareWithSumLessThanOrEqualToThreshold(int[][] prefixSum, int size, int threshold) {
        for (int i = size; i < prefixSum.length; i++) {
            for (int j = size; j < prefixSum[0].length; j++) {
                int sum = prefixSum[i][j] 
                        - prefixSum[i - size][j] 
                        - prefixSum[i][j - size] 
                        + prefixSum[i - size][j - size];
                if (sum <= threshold) {
                    return true;
                }
            }
        }
        return false;   
    }
}