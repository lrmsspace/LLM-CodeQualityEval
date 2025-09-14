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
        List<Integer> ans = new ArrayList<>();
        int row = matrix.length;
        int col = matrix[0].length;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]<min){
                    min = matrix[i][j];
                }
                if(matrix[i][j]>max){
                    max = matrix[i][j];
                }
            }
        }
        for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
              if(matrix[i][j]==min){
                  for(int k=0;k<row;k++){
                      if(matrix[k][j]>min){
                          min = Integer.MAX_VALUE;
                          break;
                      }
                  }
              }
           }
        }
        for(int i=0;i<col;i++){
           for(int j=0;j<row;j++){
              if(matrix[j][i]==max){
                  for(int k=0;k<col;k++){
                      if(matrix[j][k]<max){
                          max = Integer.MIN_VALUE;
                          break;
                      }
                  }
              }
           }
        }
        if(min!=Integer.MAX_VALUE && max!=Integer.MIN_VALUE){
            ans.add(min);
        }
        return ans;
    }
}