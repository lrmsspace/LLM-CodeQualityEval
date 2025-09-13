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
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        List<Integer> luckyNumbers = new ArrayList<>();
        int m = matrix.length, n = matrix[0].length;
        
        // Find the minimum and maximum in each row
        int[] rowMin = new int[m];
        int[] rowMax = new int[m];
        for (int i = 0; i < m; i++) {
            rowMin[i] = Integer.MAX_VALUE;
            rowMax[i] = Integer.MIN_VALUE;
            for (int j = 0; j < n; j++) {
                rowMin[i] = Math.min(rowMin[i], matrix[i][j]);
                rowMax[i] = Math.max(rowMax[i], matrix[i][j]);
            }
        }
        
        // Check if each number in the column is the maximum in its row
        for (int j = 0; j < n; j++) {
            boolean isLucky = true;
            for (int i = 0; i < m; i++) {
                if (matrix[i][j]!= rowMax[i]) {
                    isLucky = false;
                    break;
                }
            }
            if (isLucky) {
                luckyNumbers.add(rowMax[j]);
            }
        }
        
        return luckyNumbers;
        
    }
}