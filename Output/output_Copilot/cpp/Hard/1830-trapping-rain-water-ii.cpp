/**https://leetcode.com/problems/trapping-rain-water-ii/ */
//Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
// 
//Example 1:
//Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
//Output: 4
//Explanation: After the rain, water is trapped between the blocks.
//We have two small ponds 1 and 3 units trapped.
//The total volume of water trapped is 4.
//Example 2:
//Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
//Output: 10
// 
//Constraints:
//	m == heightMap.length
//	n == heightMap[i].length
//	1 <= m, n <= 200
//	0 <= heightMap[i][j] <= 2 * 104
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) {
            return 0;
        }
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[m - 1][i], {m - 1, i}});
            visited[0][i] = true;
            visited[m - 1][i] = true;
        }
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int res = 0;
        int curMax = INT_MIN;
        while (!pq.empty()) {
            auto [h, p] = pq.top();
            pq.pop();
            curMax = max(curMax, h);
            int x = p.first;
            int y = p.second;
            for (auto dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (heightMap[nx][ny] < curMax) {
                        res += curMax - heightMap[nx][ny];
                    }
                    pq.push({heightMap[nx][ny], {nx, ny}});
                }
            }
        }
        return res;        
    }
};