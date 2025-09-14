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
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = INT_MAX;
        for (int i = 0; i < m; ++i) {
            int flip = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != grid[m-i-1][j]) flip++;
            }
            res = min(res, flip);
        }
        for (int j = 0; j < n; ++j) {
            int flip = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] != grid[i][n-j-1]) flip++;
            }
            res = min(res, flip);
        }
        return res;
    }
};