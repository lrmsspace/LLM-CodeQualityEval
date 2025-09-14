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
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'X') {
                    // Check for valid submatrices starting from (i, j)
                    for (int k = i; k < m; ++k) {
                        for (int l = j; l < n; ++l) {
                            if (grid[k][l] == 'X') {
                                // Check if the submatrix has equal frequency of 'X' and 'Y'
                                int xCount = 0;
                                int yCount = 0;
                                for (int p = i; p <= k; ++p) {
                                    for (int q = j; q <= l; ++q) {
                                        if (grid[p][q] == 'X') {
                                            xCount++;
                                        } else if (grid[p][q] == 'Y') {
                                            yCount++;
                                        }
                                    }
                                }
                                if (xCount == yCount && xCount > 0) {
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};