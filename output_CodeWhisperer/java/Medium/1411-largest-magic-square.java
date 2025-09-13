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
class Solution {
    public int largestMagicSquare(int[][] grid) 
    {
        int m = grid.length, n = grid[0].length;
        int[][] rowSum = new int[m][n + 1], colSum = new int[n][m + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[j][i + 1] = colSum[j][i] + grid[i][j];
            }
        }
        for (int k = Math.min(m, n); k > 1; k--) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    int sum = rowSum[i][j + k] - rowSum[i][j];
                    if (sum != colSum[j][i + k] - colSum[j][i]) continue;
                    int d1 = 0, d2 = 0;
                    for (int l = 0; l < k; l++) {
                        d1 += grid[i + l][j + l];
                        d2 += grid[i + l][j + k - 1 - l];
                    }
                    if (d1 == d2 && d1 == sum) return k;
                }
            }
            }
                
    }
}