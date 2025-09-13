/**https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/ */
//You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.
//Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.
//Two paths are considered different if they do not have exactly the same sequence of visited cells.
// 
//Example 1:
//Input: grid = [[1,1],[3,4]]
//Output: 8
//Explanation: The strictly increasing paths are:
//- Paths with length 1: [1], [1], [3], [4].
//- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
//- Paths with length 3: [1 -> 3 -> 4].
//The total number of paths is 4 + 3 + 1 = 8.
//Example 2:
//Input: grid = [[1],[2]]
//Output: 3
//Explanation: The strictly increasing paths are:
//- Paths with length 1: [1], [2].
//- Paths with length 2: [1 -> 2].
//The total number of paths is 2 + 1 = 3.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 1000
//	1 <= m * n <= 105
//	1 <= grid[i][j] <= 105
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        auto cmp = [&](pair<int, int> a, pair<int, int> b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        };
        
        vector<pair<int, int>> cells;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cells.emplace_back(i, j);
        
        sort(cells.begin(), cells.end(), cmp);
        
        for (auto& cell : cells) {
            int x = cell.first, y = cell.second;
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > grid[x][y]) {
                    dp[nx][ny] = (dp[nx][ny] + dp[x][y]) % MOD;
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                result = (result + dp[i][j]) % MOD;
        
        return result;

    }
};