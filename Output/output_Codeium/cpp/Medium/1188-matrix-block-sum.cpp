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
        int m = mat.size(), n = mat[0].size(), mm = m + 2 * k, nn = n + 2 * k;
        vector<vector<int>> sum(mm, vector<int>(nn, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                sum[i + k][j + k] += mat[i][j];
        for (int i = 0; i < mm; ++i)
            for (int j = 0; j < nn - 1; ++j)
                sum[i][j + 1] += sum[i][j];
        for (int i = 0; i < mm - 1; ++i)
            for (int j = 0; j < nn; ++j)
                sum[i + 1][j] += sum[i][j];

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans[i][j] = sum[i + k][j + k] - sum[i + k][j] - sum[i][j + k] + sum[i][j];
        return ans; 
    }
};