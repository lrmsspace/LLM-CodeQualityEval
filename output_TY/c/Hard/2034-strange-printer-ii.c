/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//	On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//	Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.
// 
//Example 1:
//Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
//Output: true
//Example 2:
//Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
//Output: true
//Example 3:
//Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
//Output: false
//Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
// 
//Constraints:
//	m == targetGrid.length
//	n == targetGrid[i].length
//	1 <= m, n <= 60
//	1 <= targetGrid[row][col] <= 60
bool isPrintable(int** targetGrid, int targetGridSize, int* targetGridColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[60], b[60], c[60], d[60], e[60], f[60], g[60], h[60], i[60], j[60], k[60], l[60], m[60], n[60], o[60], p[60],q[60], r[60], s[60], t[60],  u[60], v[60], w[60], x[60], y[60], z[60];   
    for (i = 0; i < 60; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        d[i] = 0;
        e[i] = 0;
        f[i] = 0;
        g[i] = 0;
        h[i] = 0;
        i[i] = 0;
    }
    for (i = 0; i < targetGridSize; i++) {
        for (j = 0; j < targetGridColSize[i]; j++) {
            a[targetGrid[i][j]] = i;
            b[targetGrid[i][j]] = j;
            c[targetGrid[i][j]] = i;
            d[targetGrid[i][j]] = j;
        }
    }
    for (i = 1; i <= 60; i++) {
        if (a[i] == 0) continue;
        for (j = a[i]; j <= c[i]; j++) {
            for (k = b[i]; k <= d[i]; k++) {
                if (targetGrid[j][k] != i) return false;
            }
        }
    }
    return true;
}