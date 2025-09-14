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
    int* visited = (int*)malloc(sizeof(int) * m * n);
    memset(visited, 0, sizeof(int) * m * n);
    int* queue = (int*)malloc(sizeof(int) * m * n * 2);
    int front = 0, rear = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                queue[rear++] = i * n + j;
                visited[i * n + j] = 1;
            }
        }
    }
    int* dx = (int*)malloc(sizeof(int) * 4);
    dx[0] = -1;
    dx[1] = 1;
    dx[2] = 0;
    dx[3] = 0;
    int* dy = (int*)malloc(sizeof(int) * 4);
    dy[0] = 0;
    dy[1] = 0;
    dy[2] = -1;
    dy[3] = 1;
    int ans = 0;
    while (front < rear) {
        int x = queue[front++] / n;
        int y = queue[front++] % n;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx * n + ny]) {
                if (heightMap[x][y] > heightMap[nx][ny]) {
                    ans += heightMap[x][y] - heightMap[nx][ny];
                    heightMap[nx][ny] = heightMap[x][y];
                }
                queue[rear++] = nx * n + ny;
                visited[nx * n + ny] = 1;
            }
        }
    }
    free(visited);
    free(queue);
    free(dx);
    free(dy);
    return ans;
    
}