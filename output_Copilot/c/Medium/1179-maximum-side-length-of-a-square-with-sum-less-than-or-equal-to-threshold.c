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
int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize, n = *matColSize;
    int prefixSum[m + 1][n + 1];
    memset(prefixSum, 0, sizeof(prefixSum));

    // Compute prefix sum
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefixSum[i][j] = mat[i - 1][j - 1] 
                            + prefixSum[i - 1][j] 
                            + prefixSum[i][j - 1] 
                            - prefixSum[i - 1][j - 1];
        }
    }

    int maxSide = 0;

    // Check all possible square sizes
    for (int side = 1; side <= fmin(m, n); side++) {
        for (int i = side; i <= m; i++) {
            for (int j = side; j <= n; j++) {
                int sum = prefixSum[i][j] 
                        - prefixSum[i - side][j] 
                        - prefixSum[i][j - side] 
                        + prefixSum[i - side][j - side];
                if (sum <= threshold) {
                    maxSide = fmax(maxSide, side);
                }
            }
        }
    }

    return maxSide;
}