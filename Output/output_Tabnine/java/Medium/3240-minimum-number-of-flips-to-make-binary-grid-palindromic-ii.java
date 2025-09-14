/*
 You are given an m x n binary matrix grid.
 A row or column is considered palindromic if its values read the same forward and backward.
 You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
 Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4.
 Example 1:
 Input: grid = [[1,0,0],[0,1,0],[0,0,1]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [[0,1],[0,1],[0,0]]
 Output: 2
 Explanation:
 Example 3:
 Input: grid = [[1],[1]]
 Output: 2
 Explanation:
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m * n <= 2 * 105
 0 <= grid[i][j] <= 1
*/

class Solution {
    public int minFlips(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int flipCount = 0;
        int onesCount = 0;
        
        // Count the number of ones and flip the count of 0s to 1s
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                onesCount += grid[i][j];
                if (grid[i][j] == 0) {
                    flipCount++;
                }
            }
        }
        
        // If the total number of ones is not divisible by 4, return -1
        if (onesCount % 4!= 0) {
            return -1;
        }
        
        // Calculate the minimum number of flips required to make all rows and columns palindromic
        int minFlips = Math.min(flipCount, m - flipCount);  
        return minFlips;
        
    }
}