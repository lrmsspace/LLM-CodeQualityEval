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
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i * n});
            pq.push({heightMap[i][n - 1], i * n + n - 1});
        }
        for (int i = 0; i < n; ++i) {
            pq.push({heightMap[0][i], i});
            pq.push({heightMap[m - 1][i], (m - 1) * n + i});
        }
        int res = 0;
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [h, t] = pq.top(); pq.pop();
            int x = t / n, y = t % n;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && heightMap[nx][ny] < h) {
                    res += h - heightMap[nx][ny];
                    heightMap[nx][ny] = h;
                    pq.push({h, nx * n + ny});
                }
            }
        }
        return res;
    }
};