/**https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/ */
//Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
// 
//Example 1:
//Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
//Example 2:
//Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
//Output: false
//Explanation: It is impossible to make mat equal to target by rotating mat.
//Example 3:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
// 
//Constraints:
//	n == mat.length == target.length
//	n == mat[i].length == target[i].length
//	1 <= n <= 10
//	mat[i][j] and target[i][j] are either 0 or 1.
bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int a[4][4], b[4][4], c[4][4], d[4][4], e[4][4], f[4][4], g[4][4], h[4][4], j1[4][4], j2[4][4], j3[4][4], j4[4][4];
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a[i][j] = mat[i][j];
            b[i][j] = target[i][j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            c[i][j] = a[j][3 - i];
            d[i][j] = a[3 - j][i];
            e[i][j] = a[3 - i][3 - j];
            f[i][j] = a[j][i];
            g[i][j] = b[j][3 - i];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            h[i][j] = b[3 - j][i];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            j1[i][j] = a[i][j] ^ b[i][j];
            j2[i][j] = a[i][j] ^ g[i][j];
            j3[i][j] = a[i][j] ^ h[i][j];
            j4[i][j] = a[i][j] ^ f[i][j];
            if (j1[i][j] == 0 && j2[i][j] == 0 && j3[i][j] == 0 && j4[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}