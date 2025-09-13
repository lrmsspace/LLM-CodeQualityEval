/**https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/ */
//You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0).
//Starting from the cell (i, j), you can move to one of the following cells:
//	Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
//	Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
//Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.
// 
//Example 1:
//Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
//Output: 4
//Explanation: The image above shows one of the paths that visits exactly 4 cells.
//Example 2:
//Input: grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
//Output: 3
//Explanation: The image above shows one of the paths that visits exactly 3 cells.
//Example 3:
//Input: grid = [[2,1,0],[1,0,0]]
//Output: -1
//Explanation: It can be proven that no path exists.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	0 <= grid[i][j] < m * n
//	grid[m - 1][n - 1] == 0
int minimumVisitedCells(int** grid, int gridSize, int* gridColSize){    
    int m = gridSize, n = *gridColSize;
    int i, j, k, l, r, c, d, e, f, g, h, t, u, v, w, x, y, z;
    int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    a = (int*)malloc(sizeof(int) * m * n);
    b = (int*)malloc(sizeof(int) * m * n);
    c = (int*)malloc(sizeof(int) * m * n);
    d = (int*)malloc(sizeof(int) * m * n);
    e = (int*)malloc(sizeof(int) * m * n);
    f = (int*)malloc(sizeof(int) * m * n);
    g = (int*)malloc(sizeof(int) * m * n);
    h = (int*)malloc(sizeof(int) * m * n);
    i = (int*)malloc(sizeof(int) * m * n);
    j = (int*)malloc(sizeof(int) * m * n);
    k = (int*)malloc(sizeof(int) * m * n);
    l = (int*)malloc(sizeof(int) * m * n);
    m = (int*)malloc(sizeof(int) * m * n);
    n = (int*)malloc(sizeof(int) * m * n);
    o = (int*)malloc(sizeof(int) * m * n);
    p = (int*)malloc(sizeof(int) * m * n);
    q = (int*)malloc(sizeof(int) * m * n);
    r = (int*)malloc(sizeof(int) * m * n);
    s = (int*)malloc(sizeof(int) * m * n);
    t = (int*)malloc(sizeof(int) * m * n);
    u = (int*)malloc(sizeof(int) * m * n);
    v = (int*)malloc(sizeof(int) * m * n);
    w = (int*)malloc(sizeof(int) * m * n);
    x = (int*)malloc(sizeof(int) * m * n);
    y = (int*)malloc(sizeof(int) * m * n);
    z = (int*)malloc(sizeof(int) * m * n);
    for (i = 0; i < m * n; i++) {
        a[i] = b[i] = c[i] = d[i] = e[i] = f[i] = g[i] = h[i] = i;
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i + grid[i][j] < m) {
                c[i * n + j] = i + grid[i][j];
            }
            if (j + grid[i][j] < n) {
                d[i * n + j] = j + grid[i][j];
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = i; k <= c[i * n + j]; k++) {
                for (l = j; l <= d[i * n + j]; l++) {
                    if (k == i && l == j) {
                        continue;
                    }
                    if (k * n + l < m * n) {
                        if (a[k * n + l] > a[i * n + j] + 1) {
                            a[k * n + l] = a[i * n + j] + 1;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = i; k <= c[i * n + j]; k++) {
                for (l = j; l <= d[i * n + j]; l++) {
                    if (k == i && l == j) {
                        continue;
                    }
                    if (k * n+ l < m * n) {
                        if (b[k * n + l] > b[i * n + j] + 1) {
                            b[k * n + l] = b[i * n + j] + 1;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = i; k <= c[i * n + j]; k++) {
                for (l = j; l <= d[i * n + j]; l++) {
                    if (k == i && l == j) {
                        continue;
                    }
                    if (k * n+ l < m * n) {
                        if (c[k * n + l] > c[i * n + j] + 1) {
                            c[k * n + l] = c[i * n + j] + 1;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = i; k <= c[i * n + j]; k++) {
                for (l = j; l <= d[i * n + j]; l++) {
                    if (k == i && l == j) {
                        continue;
                    }
                    if (k * n+ l < m * n) {
                        if (d[k * n + l] > d[i * n + j] + 1) {
                            d[k * n + l] = d[i * n + j] + 1;
                        }
                        if (k * n + l < m * n) {
                            if (e[k * n + l] > e[i * n + j] + 1) {
                                e[k * n + l] = e[i * n + j] + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = i; k <= c[i * n + j]; k++) {
                for (l = j; l <= d[i * n + j]; l++) {
                    if (k == i && l == j) {
                        continue;
                    }
                    if (k * n+ l < m * n) {
                        if (e[k * n + l] > e[i * n + j] + 1) {
                            e[k * n + l] = e[i * n + j] + 1;
                        }
                        if (k * n + l < m * n) {
                            if (f[k * n + l] > f[i * n + j] + 1) {
                                f[k * n + l] = f[i * n + j] + 1;
                            }
                        }
                        if (k * n + l < m * n) {
                            if (g[k * n + l] > g[i * n + j] + 1) {
                                g[k * n + l] = g[i * n + j] + 1;
                            }
                        }
                        if (k * n + l < m * n) {
                            if (h[k * n + l] > h[i * n + j] + 1) {
                                h[k * n + l] = h[i * n + j] + 1;
                            }
                        }   
                    }
                }
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = i; k <= c[i * n + j]; k++) {
                for (l = j; l <= d[i * n + j]; l++) {
                    if (k == i && l == j) {
                        continue;
                    }
                    if (k * n+ l < m * n) {
                        if (f[k * n + l] > f[i * n + j] + 1) {
                            f[k * n + l] = f[i * n + j] + 1;
                        }
                        if (k * n + l < m * n) {
                            if (g[k * n + l] > g[i * n + j] + 1) {
                                g[k* n + l] = g[i * n + j] +    1;
                            }
                        }
                        if (k * n + l < m * n) {
                            if (h[k * n + l] > h[i * n + j] + 1) {
                                h[k * n + l] = h[i * n + j] + 1;
                            }
                        }
                    }
                    if (k * n + l < m * n) {
                        if (g[k * n + l] > g[i * n + j] + 1) {
                            g[k * n + l] = g[i * n + j] + 1;
                        }
                        if (k * n + l < m * n) {
                            if (h[k * n + l] > h[i *n + j] + 1) {   
                                h[k * n + l] = h[i * n + j] + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    
}