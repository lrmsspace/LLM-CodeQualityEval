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
    int totalVolume = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    int** visited = (int**)malloc(heightMapSize * sizeof(int*));
    for (int i = 0; i < heightMapSize; i++) {
        visited[i] = (int*)calloc(heightMapColSize[0], sizeof(int));
    }
    int** heightMapPath = (int**)malloc(heightMapSize * sizeof(int*));
    for (int i = 0; i < heightMapSize; i++) {
        heightMapPath[i] = (int*)calloc(heightMapColSize[0], sizeof(int));
        for (int j = 0; j < heightMapColSize[0]; j++) {
            heightMapPath[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < heightMapSize; i++) {
        for (int j = 0; j < heightMapColSize[0]; j++) {
            if (i == 0 || i == heightMapSize - 1 || j == 0 || j == heightMapColSize[0] - 1) {
                pq.push({heightMap[i][j], {i, j}});
                visited[i][j] = 1;
                heightMapPath[i][j] = 0;
            }
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!pq.empty()) {
        int height = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < heightMapSize && ny >= 0 && ny < heightMapColSize[0] &&!visited[nx][ny]) {
                visited[nx][ny] = 1;
                int path = heightMapPath[x][y] + 1;
                if (path < heightMapPath[nx][ny]) {
                    totalVolume += heightMapPath[nx][ny] - path;
                    heightMapPath[nx][ny] = path;
                    pq.push({heightMap[nx][ny], {nx, ny}});
                }
            }
        }
    }
    free(visited);
    free(heightMapPath);
    return totalVolume;
}