/*
 You are given an m x n binary matrix grid.
 A row or column is considered palindromic if its values read the same forward and backward.
 You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
 Return the minimum number of cells that need to be flipped to make either all rows palindromic or all columns palindromic.
 Example 1:
 Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
 Output: 2
 Explanation:
 Flipping the highlighted cells makes all the rows palindromic.
 Example 2:
 Input: grid = [[0,1],[0,1],[0,0]]
 Output: 1
 Explanation:
 Flipping the highlighted cell makes all the columns palindromic.
 Example 3:
 Input: grid = [[1],[0]]
 Output: 0
 Explanation:
 All rows are already palindromic.
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m * n <= 2 * 105
 0 <= grid[i][j] <= 1
*/

class Solution {
    public int minFlips(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int rowFlips = 0, colFlips = 0;
        
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                count += grid[i][j];
            }
            rowFlips += Math.abs(count - m / 2);
        }
        
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = 0; i < m; i++) {
                count += grid[i][j];
            }
            colFlips += Math.abs(count - n / 2);
        }
        
        return Math.min(rowFlips, colFlips);
        
    }
}