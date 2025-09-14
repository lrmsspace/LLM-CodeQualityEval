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
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        int row = 0, col = 0, direction = 0;
        
        while (row < m && col < n) {
            result.push_back(mat[row][col]);
            
            if (direction == 0) {
                if (col == n - 1) row++;
                else if (row == 0) col++;
                else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) col++;
                else if (col == 0) row++;
                else {
                    row++;
                    col--;
                }
            }
            
            direction = 1 - direction;
        }
        
        return result;
        
    }
};