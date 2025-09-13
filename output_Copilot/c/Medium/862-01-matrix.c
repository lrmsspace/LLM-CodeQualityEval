/**https://leetcode.com/problems/01-matrix/ */
//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//The distance between two adjacent cells is 1.
// 
//Example 1:
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
//Example 2:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	mat[i][j] is either 0 or 1.
//	There is at least one 0 in mat.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * matSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * matSize);
    int i, j, k, m, n;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int** queue = (int**)malloc(sizeof(int*) * matSize * matColSize[0]);
    int front = 0, rear = 0;
    for (i = 0; i < matSize; i++) {
        res[i] = (int*)malloc(sizeof(int) * matColSize[i]);
        (*returnColumnSizes)[i] = matColSize[i];
        for (j = 0; j < matColSize[i]; j++) {
            res[i][j] = mat[i][j] ? INT_MAX : 0;
            if (!mat[i][j]) {
                queue[rear] = (int*)malloc(sizeof(int) * 2);
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
        }
    }
    while (front < rear) {
        i = queue[front][0];
        j = queue[front][1];
        front++;
        for (k = 0; k < 4; k++) {
            m = i + dir[k][0];
            n = j + dir[k][1];
            if (m >= 0 && m < matSize && n >= 0 && n < matColSize[0] && res[m][n] > res[i][j] + 1) {
                res[m][n] = res[i][j] + 1;
                queue[rear] = (int*)malloc(sizeof(int) * 2);
                queue[rear][0] = m;
                queue[rear][1] = n;
                rear++;
            }
        }
    }
    *returnSize = matSize;
    return res;    
}