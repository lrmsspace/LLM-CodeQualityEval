/**https://leetcode.com/problems/largest-magic-square/ */
//A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
//Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
// 
//Example 1:
//Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
//Output: 3
//Explanation: The largest magic square has a size of 3.
//Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
//- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
//- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
//- Diagonal sums: 5+4+3 = 6+4+2 = 12
//Example 2:
//Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
//Output: 2
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 106
int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int sum[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            sum[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i][j-1] + grid[i-1][j-1];
        }
    }
    int res = 1;
    for (int k = 2; k <= fmin(m, n); k++) {
        for (int i = 1; i <= m-k+1; i++) {
            for (int j = 1; j <= n-k+1; j++) {
                int flag = 1;
                int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
                for (int l = 0; l < k; l++) {
                    sum1 += grid[i+l][j+l];
                    sum2 += grid[i+l][j+k-1-l];
                    sum3 += grid[i][j+l];
                    sum4 += grid[i+k-1][j+l];
                }
                if (sum1 != sum2 || sum2 != sum3 || sum3 != sum4) {
                    continue;
                }
                for (int l = 0; l < k; l++) {
                    if (sum[i+l][j+k] - sum[i+l][j] != sum1 || sum[i+k][j+l] - sum[i][j+l] != sum1) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    res = k;
                }
            }
        }
    }
    return res;    
}