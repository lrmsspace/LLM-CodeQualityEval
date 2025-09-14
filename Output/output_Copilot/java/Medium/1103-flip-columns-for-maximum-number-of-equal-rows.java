/**https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/ */
//You are given an m x n binary matrix matrix.
//You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
//Return the maximum number of rows that have all values equal after some number of flips.
// 
//Example 1:
//Input: matrix = [[0,1],[1,1]]
//Output: 1
//Explanation: After flipping no values, 1 row has all values equal.
//Example 2:
//Input: matrix = [[0,1],[1,0]]
//Output: 2
//Explanation: After flipping values in the first column, both rows have equal values.
//Example 3:
//Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
//Output: 2
//Explanation: After flipping values in the first two columns, the last two rows have equal values.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 300
//	matrix[i][j] is either 0 or 1.
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> map = new HashMap<>();
        for (int[] row : matrix) {
            StringBuilder sb1 = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();
            for (int num : row) {
                sb1.append(num);
                sb2.append(1 - num);
            }
            String s1 = sb1.toString();
            String s2 = sb2.toString();
            map.put(s1, map.getOrDefault(s1, 0) + 1);
            map.put(s2, map.getOrDefault(s2, 0) + 1);
        }
        int res = 0;
        for (int value : map.values()) {
            res = Math.max(res, value);
        }
        return res;        
    }
}