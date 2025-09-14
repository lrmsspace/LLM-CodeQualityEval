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
        int[] res = new int[m * n];
        int i = 0;
        int j = 0;
        int k = 0;
        while (k < m * n) {
            res[k] = mat[i][j];
            if (i + j == 0) {
                i++;
            } else if (i == 0) {
                j++;
            } else if (j == n - 1) {
                i++;
            } else {
                i--;
                j++;
            }
            k++;
        }
        return res;
    }
}