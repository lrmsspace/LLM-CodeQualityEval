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
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        // Create a 2D prefix sum matrix
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
                prefixSum[i][j] += grid[i - 1][j - 1] == 'X'? 1 : -1;
            }
        }
        // Traverse the prefix sum matrix to find submatrices with equal frequency of 'X' and 'Y' and at least one 'X'
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = i; k <= m; ++k) {
                    for (int l = j; l <= n; ++l) {
                        int countX = prefixSum[k][l] - prefixSum[k][j - 1] - prefixSum[i - 1][l] + prefixSum[i - 1][j - 1];
                        if (countX == k - i + 1 && countX == l - j + 1) {
                            ans += (k - i + 1) * (l - j + 1);
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};