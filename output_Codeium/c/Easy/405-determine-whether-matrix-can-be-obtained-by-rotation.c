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
bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    int n = matSize;
    int t[4][n][n];
    memcpy(t[0], mat, sizeof(int) * n * n);
    for (int i = 1; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                t[i][k][n-j-1] = t[i-1][j][k];
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (t[i][j][k] != target[j][k]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) return true;
    }
    return false;
}