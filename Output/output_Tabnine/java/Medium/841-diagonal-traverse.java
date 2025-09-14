/**https://leetcode.com/problems/diagonal-traverse/ */
//Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,4,7,5,3,6,8,9]
//Example 2:
//Input: mat = [[1,2],[3,4]]
//Output: [1,2,3,4]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	-105 <= mat[i][j] <= 105
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[] result = new int[m * n];
        int index = 0;
        
        for (int i = 0; i < m + n - 1; i++) {
            if (i % 2 == 0) {
                for (int j = Math.min(i, n - 1); j >= 0; j--) {
                    result[index++] = mat[j][i - j];
                }
            } else {
                for (int j = Math.min(i, m - 1); j >= 0; j--) {
                    result[index++] = mat[i - j][j];
                }
            }
        }
        
        return result;
        
    }
}