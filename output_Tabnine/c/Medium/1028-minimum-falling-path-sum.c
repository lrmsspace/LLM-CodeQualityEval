/**https://leetcode.com/problems/minimum-falling-path-sum/ */
//Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
//A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
// 
//Example 1:
//Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
//Output: 13
//Explanation: There are two falling paths with a minimum sum as shown.
//Example 2:
//Input: matrix = [[-19,57],[-40,-5]]
//Output: -59
//Explanation: The falling path with a minimum sum is shown.
// 
//Constraints:
//	n == matrix.length == matrix[i].length
//	1 <= n <= 100
//	-100 <= matrix[i][j] <= 100
int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int** dp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
    }
    
    // Initialize the first row
    for (int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j];
    }
    
    // Fill the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int min = INT_MAX;
            if (j > 0) {
                min = fmin(min, dp[i - 1][j - 1]);
            }
            if (j < n - 1) {
                min = fmin(min, dp[i - 1][j]);
            }
            dp[i][j] = min + matrix[i][j];
        }
    }
    
    // Find the minimum sum in the last row
    int minSum = INT_MAX;
    for (int j = 0; j < n; j++) {
        minSum = fmin(minSum, dp[n - 1][j]);
    }
    
    // Free the dp table
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return minSum;
    
}