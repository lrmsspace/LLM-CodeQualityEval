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
int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int** prefixSum = (int**)malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++) {
        prefixSum[i] = (int*)malloc(sizeof(int) * (n + 1));
        memset(prefixSum[i], 0, sizeof(int) * (n + 1));
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }
    int maxSum = INT_MIN;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int x = i; x <= m; x++) {
                for (int y = j; y <= n; y++) {
                    int sum = prefixSum[x][y] - prefixSum[i - 1][y] - prefixSum[x][j - 1] + prefixSum[i - 1][j - 1];
                    if (sum <= k) {
                        maxSum = fmax(maxSum, sum);
                    }
                }
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        free(prefixSum[i]);
    }
    free(prefixSum);
    return maxSum;
    
}