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
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1){
                    pq.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
            }
        }
        while(!pq.empty()){
            auto [h, idx] = pq.top();
            pq.pop();
            int i = idx / n, j = idx % n;
            for(int k = 0; k < 4; k++){
                int x = i + dx[k], y = j + dy[k];
                if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]){
                    res += max(0, h - heightMap[x][y]);
                    pq.push({max(h, heightMap[x][y]), x * n + y});
                    visited[x][y]= true;
                }
            }
        }
        return res;
    }
};