/**https://leetcode.com/problems/lucky-numbers-in-a-matrix/ */
//Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
//A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
// 
//Example 1:
//Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
//Output: [15]
//Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
//Example 2:
//Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
//Output: [12]
//Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
//Example 3:
//Input: matrix = [[7,8],[1,2]]
//Output: [7]
//Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= n, m <= 50
//	1 <= matrix[i][j] <= 105.
//	All elements in the matrix are distinct.
import java.util.ArrayList;
import java.util.Arrays;
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] minRow = new int[m], maxCol = new int[n];
        Arrays.fill(minRow, Integer.MAX_VALUE);
        Arrays.fill(maxCol, Integer.MIN_VALUE);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minRow[i] = Math.min(matrix[i][j], minRow[i]);
                maxCol[j] = Math.max(matrix[i][j], maxCol[j]);
            }
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (minRow[i] == maxCol[j]) {
                    res.add(minRow[i]);
                }
            }
        }
        return res;       
    }
}