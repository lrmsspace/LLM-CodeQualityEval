/**https://leetcode.com/problems/largest-submatrix-with-rearrangements/ */
//You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
//Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.
// 
//Example 1:
//Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
//Output: 4
//Explanation: You can rearrange the columns as shown above.
//The largest submatrix of 1s, in bold, has an area of 4.
//Example 2:
//Input: matrix = [[1,0,1,0,1]]
//Output: 3
//Explanation: You can rearrange the columns as shown above.
//The largest submatrix of 1s, in bold, has an area of 3.
//Example 3:
//Input: matrix = [[1,1,0],[1,0,1]]
//Output: 2
//Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m * n <= 105
//	matrix[i][j] is either 0 or 1.
int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[matrixSize][*matrixColSize];
    int b[matrixSize][*matrixColSize];
    int c[matrixSize][*matrixColSize];
    int d[matrixSize][*matrixColSize];
    int e[matrixSize][*matrixColSize];
    int f[matrixSize][*matrixColSize];
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            a[i][j] = matrix[i][j];
            b[i][j] = matrix[i][j];
            c[i][j] = matrix[i][j];
            d[i][j] = matrix[i][j];
            e[i][j] = matrix[i][j];
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        a[l][j] = a[l][j] + a[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        b[l][j] = b[l][j] + b[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        c[l][j] = c[l][j] + c[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        d[l][j] = d[l][j] + d[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        e[l][j] = e[l][j] + e[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        f[l][j] = f[l][j] + f[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        a[l][j] = a[l][j] + a[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        b[l][j] = b[l][j] + b[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        c[l][j] = c[l][j] + c[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        d[l][j] = d[l][j] + d[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        e[l][j] = e[l][j] + e[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        f[l][j] = f[l][j] + f[l][k];
                    }
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            for (k = 0; k < *matrixColSize; k++) {
                if (j != k) {
                    for (l = 0; l < matrixSize; l++) {
                        a[l][j] = a[l][j] + a[l][k];
                    }
                }
            }
        }
    }
    int max = 0;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
            if (b[i][j] > max) {
                max = b[i][j];
            }
            if (c[i][j] > max) {
                                max = c[i][j];
}
        }
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < *matrixColSize; j++) {
            if (d[i][j] > max) {
                max = d[i][j];
            }
            if (e[i][j] > max) {
                max = e[i][j];
            }
            if (f[i][j] > max) {
                max = f[i][j];
}
        }
    }
    return max;

}