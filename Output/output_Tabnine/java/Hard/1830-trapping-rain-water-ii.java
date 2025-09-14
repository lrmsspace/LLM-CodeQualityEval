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
    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length, n = heightMap[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[2] - a[2]);
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.offer(new int[]{i, j, heightMap[i][j]});
            }
        }
        
        int ans = 0;
        boolean[][] visited = new boolean[m][n];
        
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int x = cur[0], y = cur[1], h = cur[2];
            
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            for (int[] dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                
                ans += Math.max(0, h - heightMap[nx][ny]);
                pq.offer(new int[]{nx, ny, Math.max(h, heightMap[nx][ny])});
            }
        }
        
        return ans;
        
    }
}