/*
 Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
 grid[0][0]
 an equal frequency of 'X' and 'Y'.
 at least one 'X'.
 Example 1:
 Input: grid = [["X","Y","."],["Y",".","."]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [["X","X"],["X","Y"]]
 Output: 0
 Explanation:
 No submatrix has an equal frequency of 'X' and 'Y'.
 Example 3:
 Input: grid = [[".","."],[".","."]]
 Output: 0
 Explanation:
 No submatrix has at least one 'X'.
 Constraints:
 1 <= grid.length, grid[i].length <= 1000
 grid[i][j] is either 'X', 'Y', or '.'.
*/

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {

    int i, j, k, l, m, n, cnt = 0, sum = 0, max_sum = 0;
    int row = gridSize, col = *gridColSize;
    int freq[10001] = {0};
    int dp[row][col];

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            dp[i][j] = (grid[i][j] == 'X') ? 0 : 1;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            sum = 0;
}
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            sum = 0;
            for (k = i; k < row; k++) {
                for (l = j; l < col; l++) {
                    sum += dp[k][l];
                    if (sum <= 10000) {
                        cnt += freq[sum];
                        freq[sum]++;
                    }
                }
            }
        }
    }
    return cnt;
}