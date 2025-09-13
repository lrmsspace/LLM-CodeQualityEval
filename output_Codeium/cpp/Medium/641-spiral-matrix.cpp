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
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        int u = 0, d = m - 1, l = 0, r = n - 1;
        vector<int> res(m * n);
        int k = 0;
        while (u <= d && l <= r) {
            for (int i = l; i <= r; i++) res[k++] = matrix[u][i];
            u++;
            for (int i = u; i <= d; i++) res[k++] = matrix[i][r];
            r--;
            if (u <= d) {
                for (int i = r; i >= l; i--) res[k++] = matrix[d][i];
                d--;
            }
            if (l <= r) {
                for (int i = d; i >= u; i--) res[k++] = matrix[i][l];
                l++;
            }
        }
        return res;
    }
};