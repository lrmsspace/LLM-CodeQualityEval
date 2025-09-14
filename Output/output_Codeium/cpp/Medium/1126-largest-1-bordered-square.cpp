/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 9
//Example 2:
//Input: grid = [[1,1,0,0]]
//Output: 1
// 
//Constraints:
//	1 <= grid.length <= 100
//	1 <= grid[0].length <= 100
//	grid[i][j] is 0 or 1
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> left(m, vector<int>(n, 0)), right(m, vector<int>(n, 0)), up(m, vector<int>(n, 0)), down(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
                    up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    right[i][j] = j == n - 1 ? 1 : right[i][j + 1] + 1;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 1) {
                    down[i][j] = i == m - 1 ? 1 : down[i + 1][j] + 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, min(min(left[i][j], right[i][j]), min(up[i][j], down[i][j])));
                }
            }
        }
        return res * res;
    }
};