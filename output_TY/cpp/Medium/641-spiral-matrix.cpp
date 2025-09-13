/**https://leetcode.com/problems/spiral-matrix/ */
//Given an m x n matrix, return all elements of the matrix in spiral order.
// 
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,3,6,9,8,7,4,5]
//Example 2:
//Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//Output: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 10
//	-100 <= matrix[i][j] <= 100
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0;
        vector<int> ans;
        while(i < m && j < n){
            for(int k = j; k < n; k++)
                ans.push_back(matrix[i][k]);
            i++;
            for(int k = i; k < m; k++)
                ans.push_back(matrix[k][n-1]);
        }
        if(i == m || j == n)
            return ans;
            for(int k = n-2; k >= j; k--)
                ans.push_back(matrix[m-1][k]);
            m--;
            for(int k = m-1; k >= i; k--)
                ans.push_back(matrix[k][j]);
                j++;
                return ans;
    }
};