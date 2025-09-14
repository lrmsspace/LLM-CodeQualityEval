/**https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/ */
//You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.
//The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
//Find the kth largest value (1-indexed) of all the coordinates of matrix.
// 
//Example 1:
//Input: matrix = [[5,2],[1,6]], k = 1
//Output: 7
//Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.
//Example 2:
//Input: matrix = [[5,2],[1,6]], k = 2
//Output: 5
//Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.
//Example 3:
//Input: matrix = [[5,2],[1,6]], k = 3
//Output: 4
//Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 1000
//	0 <= matrix[i][j] <= 106
//	1 <= k <= m * n
class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        
        // Create dp array to store XOR values for each coordinate
        int[][] dp = new int[m][n];
        
        // Create list to store all XOR values
        List<Integer> values = new ArrayList<>();
        
        // Calculate XOR values for each coordinate
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j];
                
                // Add XOR of left element if exists
                if (j > 0) {
                    dp[i][j] ^= dp[i][j-1];
                }
                
                // Add XOR of upper element if exists
                if (i > 0) {
                    dp[i][j] ^= dp[i-1][j];
                }
                
                // Subtract XOR of upper-left diagonal if exists
                // (because it was added twice above)
                if (i > 0 && j > 0) {
                    dp[i][j] ^= dp[i-1][j-1];
                }
                
                // Add current XOR value to list
                values.add(dp[i][j]);
            }
        }
        
        // Sort values in descending order
        Collections.sort(values, Collections.reverseOrder());
        
        // Return kth largest value (k is 1-indexed)
        return values.get(k - 1);
    }
        
}
