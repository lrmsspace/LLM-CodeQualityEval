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
int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize) {
    int m = heightMapSize;
    int n = heightMapColSize[0];
    int** visited = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        visited[i] = (int*)malloc(n * sizeof(int));
        memset(visited[i], 0, n * sizeof(int));
    }
    int** height = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        height[i] = (int*)malloc(n * sizeof(int));
        memcpy(height[i], heightMap[i], n * sizeof(int));
    }
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int water = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            int cur = height[i][j];
            int q[40000][2] = {{i, j}};
            int front = 0, rear = 1;
            while (front < rear) {
                int x = q[front][0], y = q[front][1];
                front++;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dir[k][0], ny = y + dir[k][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && height[nx][ny] < cur) {
                        q[rear][0] = nx, q[rear][1] = ny;
                        rear++;
                        water += cur - height[nx][ny];
                    }
                }
                visited[x][y] = 1;
            }
        }
    }
    free(visited);
    free(height);
    return water;
}