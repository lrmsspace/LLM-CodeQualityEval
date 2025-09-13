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
    int m = matrixSize, n = matrixColSize[0];
    int** prefixSum = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        prefixSum[i] = (int*)malloc(sizeof(int) * n);
        prefixSum[i][0] = matrix[i][0];
        for (int j = 1; j < n; j++) {
            prefixSum[i][j] = prefixSum[i][j - 1] + matrix[i][j];
        }
    }
    
    int maxSum = INT_MIN;
    for (int left = 0; left < n; left++) {
        for (int right = left; right < n; right++) {
            int currSum = INT_MIN;
            for (int top = 0; top < m; top++) {
                int bottom = top + (k - prefixSum[top][right] + prefixSum[top][left - 1]);
                if (bottom <= m) {
                    currSum = max(currSum, prefixSum[bottom - 1][right] - prefixSum[bottom - 1][left - 1] + prefixSum[top - 1][left - 1]);
                    maxSum = max(maxSum, currSum);
                }
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        free(prefixSum[i]);
    }
    free(prefixSum);
    
    return maxSum;
}