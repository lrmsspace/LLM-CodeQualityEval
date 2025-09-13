/**https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/ */
//You are given an m x n integer matrix mat and an integer target.
//Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.
//Return the minimum absolute difference.
//The absolute difference between two numbers a and b is the absolute value of a - b.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
//Output: 0
//Explanation: One possible choice is to:
//- Choose 1 from the first row.
//- Choose 5 from the second row.
//- Choose 7 from the third row.
//The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.
//Example 2:
//Input: mat = [[1],[2],[3]], target = 100
//Output: 94
//Explanation: The best possible choice is to:
//- Choose 1 from the first row.
//- Choose 2 from the second row.
//- Choose 3 from the third row.
//The sum of the chosen elements is 6, and the absolute difference is 94.
//Example 3:
//Input: mat = [[1,2,9,8,7]], target = 6
//Output: 1
//Explanation: The best choice is to choose 7 from the first row.
//The absolute difference is 1.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 70
//	1 <= mat[i][j] <= 70
//	1 <= target <= 800
int minimizeTheDifference(int** mat, int matSize, int* matColSize, int target){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[70][70];
    int b[70][70];
    int c[70][70];
    int d[70][70];
    int e[70][70];
    int f[70][70];
    int g[70][70];
    int h[70][70];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    memset(e, 0, sizeof(e));
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    memset(h, 0, sizeof(h));
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            a[i][j] = mat[i][j];
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            for (k = 0; k < matSize; k++) {
                for (l = 0; l < matColSize[k]; l++) {
                    b[i][j] += a[k][l];
                }
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            for (k = 0; k < matSize; k++) {
                for (l = 0; l < matColSize[k]; l++) {
                    c[i][j] += b[k][l];
                }
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            for (k = 0; k < matSize; k++) {
                for (l = 0; l < matColSize[k]; l++) {
                    d[i][j] += c[k][l];
                }
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            for (k = 0; k < matSize; k++) {
                for (l = 0; l < matColSize[k]; l++) {
                    e[i][j] += d[k][l];
                }
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            for (k = 0; k < matSize; k++) {
                for (l = 0; l < matColSize[k]; l++) {
                    f[i][j] += e[k][l];
                }
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            for (k = 0; k < matSize; k++) {
                for (l = 0; l < matColSize[k]; l++) {
                    g[i][j] += f[k][l];
                }
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            for (k = 0; k < matSize; k++) {
                for (l = 0; l < matColSize[k]; l++) {
                    h[i][j] += g[k][l];
                }
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            if (h[i][j] == target) {
                return 0;
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            for (k = 0; k < matSize; k++) {
                for (l = 0; l < matColSize[k]; l++) {
                    for (m = 0; m < matSize; m++) {
                        for (n = 0; n < matColSize[m]; n++) {
                            for (o = 0; o < matSize; o++) {
                                for (p = 0; p < matColSize[o]; p++) {
                                    for (q = 0; q < matSize; q++) {
                                        for (r = 0; r < matColSize[q]; r++) {
                                            for (s = 0; s < matSize; s++) {
                                                for (t = 0; t < matColSize[s]; t++) {   
                                                    for (u = 0; u < matSize; u++) {
                                                        for (v = 0; v < matColSize[u]; v++) {
                                                            for (w = 0; w < matSize; w++) {
                                                                for (x = 0; x < matColSize[w]; x++) {
                                                                    for (y = 0; y < matSize;y++) {
                                                                        for (z = 0; z < matColSize[y]; z++) {
                                                                            if (h[i][j] + h[k][l] + h[m][n] + h[o][p] + h[q][r] + h[s][t] + h[u][v] + h[w][x] + h[y][z] == target) {
                                                                                return 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                            }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 2;
}