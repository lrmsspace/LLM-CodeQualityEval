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
    int count_negative = 0;
    long long sum = 0, min_abs = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0) {
                count_negative++;
            }
            long long abs_value = labs(matrix[i][j]);
            sum += abs_value;
            min_abs = fmin(min_abs, abs_value);
        }
    }
    if (count_negative % 2 == 0) {
        return sum;
    }
    else {
        return sum - 2 * min_abs;
    }
}