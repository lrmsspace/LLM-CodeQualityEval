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
        vector<int> res;
        if(matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while(left <= right && top <= bottom) {
            for(int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            for(int i = top + 1; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            if(left < right && top < bottom) {
                for(int i = right - 1; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                for(int i = bottom - 1; i > top; i--) {
                    res.push_back(matrix[i][left]);
                }
            }
            left++, right--, top++, bottom--;
        }
        return res;        
    }
};