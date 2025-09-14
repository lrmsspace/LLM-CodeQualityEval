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
    int** result = (int**)malloc(matSize * sizeof(int*));
    *returnSize = matSize;
    *returnColumnSizes = (int*)malloc(matSize * sizeof(int));
    
    for (int i = 0; i < matSize; i++) {
        result[i] = (int*)malloc(matColSize[i] * sizeof(int));
        (*returnColumnSizes)[i] = matColSize[i];
    }
    
    int rows = matSize;
    int cols = matColSize[0];
    
    int queue[rows * cols][2];
    int front = 0, rear = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 0) {
                result[i][j] = 0;
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else {
                result[i][j] = INT_MAX;
            }
        }
    }
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;
        
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && result[nx][ny] > result[x][y] + 1) {
                result[nx][ny] = result[x][y] + 1;
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;
            }
        }
    }
    
    return result;
    
}