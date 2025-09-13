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
        vector<int> res(m * n);
        int idx = 0;
        for (int k = 0; k < m + n - 1; k++) {
            if (k % 2 == 0) {
                int r = min(k, m - 1);
                int c = k - r;
                while (r >= 0 && c < n) {
                    res[idx++] = mat[r][c];
                    --r;
                    ++c;
                }
            } else {
                int c = min(k, n - 1);
                int r = k - c;
                while (c >= 0 && r < m) {
                    res[idx++] = mat[r][c];
                    ++r;
                    --c;
                }
            }
        }
        return res;
    }
};