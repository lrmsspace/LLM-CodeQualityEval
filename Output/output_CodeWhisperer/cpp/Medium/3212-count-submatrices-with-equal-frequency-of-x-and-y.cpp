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

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = 0;
                int y = 0;
                if (grid[i][j] == 'X') x++;
                if (grid[i][j] == 'Y') y++;
                if (x > 0 && y > 0) ans++;
                for (int k = j + 1; k < m; k++) {
                    if (grid[i][k] == 'X') x++;
                    if (grid[i][k] == 'Y') y++;
                    if (x > 0 && y > 0) ans++;
                }
            }
        }
        return ans;
      
    }
};