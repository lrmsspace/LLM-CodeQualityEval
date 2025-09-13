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
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> pre(m, 0);
            for (int j = i; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    pre[k] += grid[j][k] == 'X' ? 1 : -1;
                }
                unordered_map<int, int> mp;
                int sum = 0;
                for (int k = 0; k < m; k++) {
                    sum += pre[k];
                    if (sum == 0) ans++;
                    if (mp.count(sum)) ans += mp[sum];
                }
            }
        }
        return ans;
        
    }
};