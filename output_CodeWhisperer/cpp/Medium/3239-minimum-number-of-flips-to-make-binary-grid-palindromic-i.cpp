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
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int row = i, col = j;
                    if(row == 0 && col == 0) {
                        res++;
                    }
                    else if(row == 0 && col > 0) {
                        if(grid[row][col-1] == 1) {
                            res--;
                        }
                        else {
                            res++;
                        }
                    }
                    else if(row > 0 && col == 0) {
                        if(grid[row-1][col] == 1) {
                            res--;
                        }
                        else {
                            res++;
                        }
                    }
                    else {
                        if(grid[row-1][col] == 1) {
                            res--;
                        }
                        else {
                            res++;
                        }
                        if(grid[row][col-1] == 1) {
                            res--;
                        }
                        else {
                            res++;
                        }
                    }
                }
            }
        }
        return res;        
    }
};