/**https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/ */
//Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
//Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
//A binary matrix is a matrix with all cells equal to 0 or 1 only.
//A zero matrix is a matrix with all cells equal to 0.
// 
//Example 1:
//Input: mat = [[0,0],[0,1]]
//Output: 3
//Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
//Example 2:
//Input: mat = [[0]]
//Output: 0
//Explanation: Given matrix is a zero matrix. We do not need to change it.
//Example 3:
//Input: mat = [[1,0,0],[1,0,0]]
//Output: -1
//Explanation: Given matrix cannot be a zero matrix.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 3
//	mat[i][j] is either 0 or 1.
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = INT_MAX;
        for (int i = 0; i < (1 << (m * n)); ++i) {
            int cnt = 0;
            vector<vector<int>> curMat = mat;
            for (int j = 0; j < m * n; ++j) {
                if (i & (1 << j)) {
                    ++cnt;
                    int x = j / n, y = j % n;
                    for (int dx = -1; dx <= 1; ++dx) {
                        for (int dy = -1; dy <= 1; ++dy) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                curMat[nx][ny] ^= 1;
                            }
                        }
                    }
                }
            }
            bool ok = true;
            for (int j = 0; j < m * n; ++j) {
                if (curMat[j / n][j % n] == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res = min(res, cnt);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};