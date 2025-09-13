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
    int i, j, k;
    int n = matSize;
    for (k = 0; k < 4; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (mat[i][j] != target[j][n - 1 - i]) {
                    goto next;
                }
            }
        }
        return true;
    next:
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (mat[i][j] != target[n - 1 - i][n - 1 - j]) {
                    goto next2;
                }
            }
        }
        return true;
    next2:
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (mat[i][j] != target[n - 1 - j][i]) {
                    goto next3;
                }
            }
        }
        return true;
    next3:
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (mat[i][j] != target[i][n - 1 - j]) {
                    goto next4;
                }
            }
        }
        return true;
    next4:
        continue;
    }
    return false;    
}