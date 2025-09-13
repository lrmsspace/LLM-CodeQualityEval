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
        int m = heightMap.length;
        int n = heightMap[0].length;
        int[][] visited = new int[m][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.offer(new int[]{i, j, heightMap[i][j]});
                    visited[i][j] = 1;
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        int res = 0;
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            for (int k = 0; k < 4; k++) {
                int x = cur[0] + dirs[k];
                int y = cur[1] + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == 0) {
                    if (cur[2] > heightMap[x][y]) {
                        res += cur[2] - heightMap[x][y];
                    }
                    pq.offer(new int[]{x, y, Math.max(heightMap[x][y], cur[2])});
                    visited[x][y] = 1;
                }
            }
        }
        return res;        
    }
}