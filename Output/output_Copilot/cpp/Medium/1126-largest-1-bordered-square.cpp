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
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> h(m, vector<int>(n, 0)), v(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    h[i][j] = j == 0 ? 1 : h[i][j - 1] + 1;
                    v[i][j] = i == 0 ? 1 : v[i - 1][j] + 1;
                }
            }
        }
        for (int len = min(m, n); len > 0; len--) {
            for (int i = 0; i < m - len + 1; i++) {
                for (int j = 0; j < n - len + 1; j++) {
                    if (h[i][j + len - 1] >= len && h[i + len - 1][j + len - 1] >= len &&
                        v[i + len - 1][j] >= len && v[i + len - 1][j + len - 1] >= len) {
                        return len * len;
                    }
                }
            }
        }
        return 0;        
    }
};