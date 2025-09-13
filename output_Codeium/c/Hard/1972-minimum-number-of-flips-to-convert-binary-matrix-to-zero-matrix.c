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
int minFlips(int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = *matColSize;
    int dirs[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
    int mask = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1) {
                mask |= 1 << (i * n + j);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < (1 << (m * n)) - 1; ++i) {
        int cur = 0;
        for (int j = 0; j < m * n; ++j) {
            if ((i >> j) & 1) {
                for (int k = 0; k < 5; ++k) {
                    int ni = j / n + dirs[k][0];
                    int nj = j % n + dirs[k][1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        cur ^= 1 << (ni * n + nj);
                    }
                }
            }
        }
        if ((cur ^ mask) == 0) {
            int cnt = 0;
            for (int j = 0; j < m * n; ++j) {
                if ((i >> j) & 1) {
                    ++cnt;
                }
            }
            res = res == 0 ? cnt : min(res, cnt);
        }
    }
    return res == 0 ? -1 : res;
}