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
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int **ans, **visited;
    int *cols;
    int *rows;
    int *cnt;
    int *cnt2;
    int *cnt3;
    int *cnt4;
    int *cnt5;
    int *cnt6;
    int*cnt7;
    int *cnt8;
    queue_t *q;
    q = createQueue();
    ans = (int**)malloc(sizeof(int*)*matSize);
    for(i=0;i<matSize;i++){
        ans[i] = (int*)malloc(sizeof(int)*matColSize[i]);
    }
    visited = (int**)malloc(sizeof(int*)*matSize);
    for(i=0;i<matSize;i++){
        visited[i] = (int*)malloc(sizeof(int)*matColSize[i]);
    }
    cols = (int*)malloc(sizeof(int)*matSize);
    rows = (int*)malloc(sizeof(int)*matColSize[0]);
    for(i=0;i<matSize;i++){
        cols[i] = 0;
    }
    for(i=0;i<matColSize[0];i++){
        rows[i] = 0;
    }
    for(i=0;i<matSize;i++){
        for(j=0;j<matColSize[i];j++){
            visited[i][j] = 0;
        }
    }
    return dfs(mat,matSize,matColSize,0,0,visited,rows,cols);
}