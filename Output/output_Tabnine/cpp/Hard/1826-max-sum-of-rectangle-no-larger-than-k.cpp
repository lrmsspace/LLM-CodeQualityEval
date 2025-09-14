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
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int maxSum = INT_MIN;
        
        // Initialize prefix sum array
        vector<vector<int>> prefixSum(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefixSum[i][j] = matrix[i][j];
                if (i > 0) {
                    prefixSum[i][j] += prefixSum[i-1][j];
                }
                if (j > 0) {
                    prefixSum[i][j] += prefixSum[i][j-1];
                }
                if (i > 0 && j > 0) {
                    prefixSum[i][j] -= prefixSum[i-1][j-1];
                }
            }
        }
        
        // Iterate through all possible submatrices and find the maximum sum
        for (int left = 0; left < cols; left++) {
            for (int right = left; right < cols; right++) {
                for (int top = 0; top < rows; top++) {
                    int bottom = top;
                    while (bottom < rows && prefixSum[bottom][right] - prefixSum[bottom][left-1] - prefixSum[top-1][right] + prefixSum[top-1][left-1] <= k) {
                        maxSum = max(maxSum, prefixSum[bottom][right] - prefixSum[bottom][left-1] - prefixSum[top-1][right] + prefixSum[top-1][left-1]);
                        bottom++;
                    }
                }
            }
        }
        
        return maxSum;
        
    }
};