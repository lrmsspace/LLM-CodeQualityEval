/**https://leetcode.com/problems/maximum-matrix-sum/ */
//You are given an n x n integer matrix. You can do the following operation any number of times:
//	Choose any two adjacent elements of matrix and multiply each of them by -1.
//Two elements are considered adjacent if and only if they share a border.
//Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
// 
//Example 1:
//Input: matrix = [[1,-1],[-1,1]]
//Output: 4
//Explanation: We can follow the following steps to reach sum equals 4:
//- Multiply the 2 elements in the first row by -1.
//- Multiply the 2 elements in the first column by -1.
//Example 2:
//Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
//Output: 16
//Explanation: We can follow the following step to reach sum equals 16:
//- Multiply the 2 last elements in the second row by -1.
// 
//Constraints:
//	n == matrix.length == matrix[i].length
//	2 <= n <= 250
//	-105 <= matrix[i][j] <= 105
long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    long long prefixSum[n][n];
    memset(prefixSum, 0, sizeof(prefixSum));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prefixSum[i][j] = matrix[i][j];
            if (i > 0) prefixSum[i][j] += prefixSum[i - 1][j];
            if (j > 0) prefixSum[i][j] += prefixSum[i][j - 1];
            if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i - 1][j - 1];
        }
    }
    
    long long maxSum = INT_MIN;
    for (int left = 0; left < n; left++) {
        for (int right = left; right < n; right++) {
            long long tempSum = prefixSum[n - 1][right];
            if (left > 0) tempSum -= prefixSum[left - 1][right];
            if (left > 0 && right > 0) tempSum += prefixSum[left - 1][left - 1];
            maxSum = fmax(maxSum, tempSum);
        }
    }
    
    return maxSum;
    
}