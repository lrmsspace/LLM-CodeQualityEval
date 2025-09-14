/**https://leetcode.com/problems/sort-the-matrix-diagonally/ */
//A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
//Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
// 
//Example 1:
//Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
//Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
//Example 2:
//Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
//Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 100
//	1 <= mat[i][j] <= 100
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h, j1, j2, j3, j4, j5, j6, j7, j8, j9, j10, j1
    1, j2, j3, j4, j5, j6, j7, j8, j9, j10;
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a = i; b = j;
            while (a >= 0 && b >= 0) {
                j1[a][b] = mat[a][b];
                a--; b--;
            }
            qsort(j1, i - a + 1,sizeof(int), cmp);
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a = i; b = j;
            while (a >= 0 && b < matColSize[i]) {
                j2[a][b] = mat[a][b];
                a--; b++;
            }
            qsort(j2, i - a +1,sizeof(int), cmp);
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a = i; b = j;
            while (a < matSize && b >= 0) {
                j3[a][b] = mat[a][b];
                a++; b--;
            }
            qsort(j3, a - i,sizeof(int),cmp);
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a = i; b = j;
            while (a < matSize && b < matColSize[i]) {
                j4[a][b] = mat[a][b];
                a++; b++;
            }
            qsort(j4, a - i,sizeof(int),cmp);
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a = i; b = j;
            while (a >= 0 && b >= 0) {
                mat[a][b] = j1[a][b];
                a--; b--;
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a = i; b = j;
            while (a >= 0 && b < matColSize[i]) {
                mat[a][b] = j2[a][b];
                a--; b++;
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a = i; b = j;
            while (a < matSize && b >= 0) {
                mat[a][b] = j3[a][b];
                a++; b--;
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a = i; b = j;
            while (a < matSize && b < matColSize[i]) {
                mat[a][b] = j4[a][b];
                a++; b++;
            }
        }
    }
    return mat;
}