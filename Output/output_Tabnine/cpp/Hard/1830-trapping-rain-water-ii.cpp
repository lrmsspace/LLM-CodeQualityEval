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
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = visited[i][n - 1] = true;
        }
        
        for (int j = 1; j < n - 1; ++j) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m - 1][j], {m - 1, j}});
            visited[0][j] = visited[m - 1][j] = true;
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int ans = 0;
        
        while (!pq.empty()) {
            int curHeight = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    ans += max(0, curHeight - heightMap[nx][ny]);
                    pq.push({max(curHeight, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }
        
        return ans;
        
    }
};