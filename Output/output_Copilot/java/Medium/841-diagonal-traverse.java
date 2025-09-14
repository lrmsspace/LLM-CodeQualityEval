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
        if (mat.length == 0 || mat[0].length == 0) return new int[0];
        int m = mat.length, n = mat[0].length;
        int[] result = new int[m * n];
        int index = 0;
        for (int d = 0; d < m + n - 1; d++) {
            if (d % 2 == 0) {
                for (int i = Math.min(d, m - 1); i >= Math.max(0, d - n + 1); i--) {
                    result[index++] = mat[i][d - i];
                }
            } else {
                for (int i = Math.max(0, d - n + 1); i <= Math.min(d, m - 1); i++) {
                    result[index++] = mat[i][d - i];
                }
            }
        }
        return result;        
    }
}