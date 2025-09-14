/*
 You are given a 0-indexed integer matrix grid and an integer k.
 Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
 Example 1:
 Input: grid = [[7,6,3],[6,6,1]], k = 18
 Output: 4
 Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
 Example 2:
 Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
 Output: 6
 Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
 Constraints:
 m == grid.length 
 n == grid[i].length
 1 <= n, m <= 1000 
 0 <= grid[i][j] <= 1000
 1 <= k <= 109
*/

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i > 0 && j > 0) {
                    grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
                }
                else if(i > 0) {
                    grid[i][j] += grid[i-1][j];
                }
                else if(j > 0) {
                    grid[i][j] += grid[i][j-1];
                }
                if(grid[i][j] <= k) {
                    res++;
                }
            }
        }
        return res;

    }
};