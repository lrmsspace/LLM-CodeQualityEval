/**https://leetcode.com/problems/matrix-block-sum/ */
//Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
//	i - k <= r <= i + k,
//	j - k <= c <= j + k, and
//	(r, c) is a valid position in the matrix.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//Output: [[12,21,16],[27,45,33],[24,39,28]]
//Example 2:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
//Output: [[45,45,45],[45,45,45],[45,45,45]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n, k <= 100
//	1 <= mat[i][j] <= 100
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = mat[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = max(0, i - k), c1 = max(0, j - k), r2 = min(m, i + k + 1), c2 = min(n, j + k + 1);
                res[i][j] = sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1];
            }
        }
        return res;   
    }
};