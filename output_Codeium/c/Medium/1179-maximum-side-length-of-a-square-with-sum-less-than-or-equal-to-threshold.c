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
    int m = matSize, n = matColSize[0];
    int prefix[m+1][n+1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            prefix[i][j] = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            prefix[i+1][j+1] = prefix[i][j+1] + prefix[i+1][j] - prefix[i][j] + mat[i][j];
    int maxSide = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; i+k <= m && j+k <= n; k++) {
                int sum = prefix[i+k][j+k] - prefix[i+k][j] - prefix[i][j+k] + prefix[i][j];
                if (sum <= threshold)
                    maxSide = k+1;
                else
                    break;
            }
    return maxSide;
}