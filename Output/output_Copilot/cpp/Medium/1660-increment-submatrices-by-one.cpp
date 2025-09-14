/**https://leetcode.com/problems/increment-submatrices-by-one/ */
//You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.
//You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:
//	Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all row1i <= x <= row2i and col1i <= y <= col2i.
//Return the matrix mat after performing every query.
// 
//Example 1:
//Input: n = 3, queries = [[1,1,2,2],[0,0,1,1]]
//Output: [[1,1,0],[1,2,1],[0,1,1]]
//Explanation: The diagram above shows the initial matrix, the matrix after the first query, and the matrix after the second query.
//- In the first query, we add 1 to every element in the submatrix with the top left corner (1, 1) and bottom right corner (2, 2).
//- In the second query, we add 1 to every element in the submatrix with the top left corner (0, 0) and bottom right corner (1, 1).
//Example 2:
//Input: n = 2, queries = [[0,0,1,1]]
//Output: [[1,1],[1,1]]
//Explanation: The diagram above shows the initial matrix and the matrix after the first query.
//- In the first query we add 1 to every element in the matrix.
// 
//Constraints:
//	1 <= n <= 500
//	1 <= queries.length <= 104
//	0 <= row1i <= row2i < n
//	0 <= col1i <= col2i < n
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (auto& q : queries) {
            res[q[0]][q[1]]++;
            if (q[2] + 1 < n) res[q[2] + 1][q[1]]--;
            if (q[3] + 1 < n) res[q[0]][q[3] + 1]--;
            if (q[2] + 1 < n && q[3] + 1 < n) res[q[2] + 1][q[3] + 1]++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                res[i][j] += res[i][j - 1];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] += res[i - 1][j];
            }
        }
        return res;        
    }
};