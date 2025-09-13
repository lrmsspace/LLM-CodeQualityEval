/**https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/ */
//Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
// 
//Example 1:
//Input: n = 13, k = 2
//Output: 10
//Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
//Example 2:
//Input: n = 1, k = 1
//Output: 1
// 
//Constraints:
//	1 <= k <= n <= 109
class Solution {
    public int findKthNumber(int n, int k) {
        // Initialize the first row of the matrix with numbers from 1 to n
        int[][] matrix = new int[n+1][n+1];
        for (int i = 1; i <= n; i++) {
            matrix[1][i] = i;
        }
        
        // Iterate from the second row to the last row
        for (int i = 2; i <= n; i++) {
            // Calculate the sum of the current row
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                sum += matrix[i-1][j];
                
                // If the sum is greater than or equal to k, update the current cell with the number of smaller numbers
                if (sum >= k) {
                    matrix[i][j] = j;
                } else {
                    // If the sum is less than k, update the current cell with the sum of smaller numbers
                    matrix[i][j] = sum;
                }
            }
        }
        
        // Return the kth smallest number in the lexicographical order
        return matrix[n][k];
        
    }
}