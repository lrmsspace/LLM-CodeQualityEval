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
    int m = matSize, n = matColSize[0];
    int* parent = (int*)malloc(m * n * sizeof(int));
    int* size = (int*)malloc(m * n * sizeof(int));
    int* top = (int*)malloc(m * n * sizeof(int));
    int directions[5] = {0, 1, 0, -1, 0};
    int** copy = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        copy[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            copy[i][j] = mat[i][j];
        }
    }
    for (int i = 0; i < m * n; i++) {
        parent[i] = i;
        size[i] = 1;
        top[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (copy[i][j] == 1) {
                if (i > 0 && copy[i - 1][j] == 1) {
                    unionSet(parent, size, top, i * n + j, (i - 1) * n + j);
                }
                if (j > 0 && copy[i][j - 1] == 1) {
                    unionSet(parent, size, top, i * n + j, i * n + j - 1);
                }
            }
        }
    }
    int result = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < n; l++) {
                    if (copy[k][l] == 1) {
                        int root = find(parent, i * n + j);
                        int root2 = find(parent, k * n + l);
                        if (root != root2) {
                            count++;
                        }
                    }
                }
            }
            if (count % 2 ==
 0) {
                result = fmin(result, count / 2);
            }
            }
            }
            for (int i = 0; i < m; i++) {
            free(copy[i]);
            }
            free(copy);
            free(parent);
            free(size);
            free(top);
            return result == INT_MAX ? -1 : result;
            
}