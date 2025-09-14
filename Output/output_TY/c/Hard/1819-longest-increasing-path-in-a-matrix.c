/**https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */
//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
// 
//Example 1:
//Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
//Output: 4
//Explanation: The longest increasing path is [1, 2, 6, 9].
//Example 2:
//Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
//Output: 4
//Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//Example 3:
//Input: matrix = [[1]]
//Output: 1
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 200
//	0 <= matrix[i][j] <= 231 - 1
int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, jj, kk, ll, mm, nn, pp, qq, rr, ss, tt, uu, vv, ww, xx, yy, zz, aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, k    ;
    int max, max_i, max_j, max_k, max_l, max_m, max_n, max_p, max_q, max_r, max_s, max_t, max_u, max_v, max_w, max_x, max_y, max_z, max_a, max_b, max_c, max_d, max_e, max_f, max_g, max_h, max_i, max_j, max_k, max_l, max = 0;
    for(i = 0; i < matrixSize; i++){
        for(j = 0; j < matrixColSize[i]; j++){
            max = 0;
            for(k = 0; k < matrixSize; k++){
                for(l = 0; l < matrixColSize[k]; l++){
                    if(matrix[i][j] < matrix[k][l]){
                        max =max > longestIncreasingPath(matrix, k, l) ? max : longestIncreasingPath(matrix, k, l) + 1;
                        longestIncreasingPath(matrix, k, l);
                    }
                }
            }
        }
    }
    return max + 1;
}