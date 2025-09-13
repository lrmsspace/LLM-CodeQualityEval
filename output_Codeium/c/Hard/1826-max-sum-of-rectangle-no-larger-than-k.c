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
    int maxSum = INT_MIN;
    int rows = matrixSize;
    int cols = *matrixColSize;
    
    for (int l = 0; l < cols; l++) {
        int* rowSums = (int*)calloc(rows, sizeof(int));
        for (int r = l; r < cols; r++) {
            for (int i = 0; i < rows; i++) {
                rowSums[i] += matrix[i][r];
            }
            
            int sum = 0, maxSumSubarray = INT_MIN;
            set<int> cumSet;
            cumSet.insert(0);
            for (int i = 0; i < rows; i++) {
                sum += rowSums[i];
                auto it = cumSet.lower_bound(sum - k);
                if (it != cumSet.end()) {
                    maxSumSubarray = max(maxSumSubarray, sum - *it);
                }
                cumSet.insert(sum);
            }
            maxSum = max(maxSum, maxSumSubarray);
        }
        free(rowSums);
    }
    
    return maxSum;
}   