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
    int m = heightMapSize, n = heightMapColSize[0];
    int* visited = (int*)malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i * n + j] = 0;
        }
    }
    int** pq = (int**)malloc(m * n * sizeof(int*));
    int pqSize = 0;
    for (int i = 0; i < m; i++) {
        visited[i * n] = 1;
        visited[i * n + n - 1] = 1;
        pq[pqSize++] = (int*)malloc(3 * sizeof(int));
        pq[pqSize - 1][0] = heightMap[i][0];
        pq[pqSize - 1][1] = i;
        pq[pqSize - 1][2] = 0;
        pq[pqSize++] = (int*)malloc(3 * sizeof(int));
        pq[pqSize - 1][0] = heightMap[i][n - 1];
        pq[pqSize - 1][1] = i;
        pq[pqSize - 1][2] = n - 1;
    }
    for (int j = 1; j < n - 1; j++) {
        visited[j] = 1;
        visited[(m - 1) * n + j] = 1;
        pq[pqSize++] = (int*)malloc(3 * sizeof(int));
        pq[pqSize - 1][0] = heightMap[0][j];
        pq[pqSize - 1][1] = 0;
        pq[pqSize - 1][2] = j;
        pq[pqSize++] = (int*)malloc(3 * sizeof(int));
        pq[pqSize - 1][0] = heightMap[m - 1][j];
        pq[pqSize - 1][1] = m - 1;
        pq[pqSize - 1][2] = j;
    }
    qsort(pq, pqSize, sizeof(int*), cmp);
    int result = 0;
    int* dirs = (int*)malloc(4 * sizeof(int));
    dirs[0] = 0; dirs[1] = 1; dirs[2] = 0; dirs[3] = -1;
    dirs = (int*)realloc(dirs, 8 * sizeof(int));
    dirs[4] = -1; dirs[5] = 0; dirs[6] = 1; dirs[7] = 0;

    while (pqSize > 0) {
        int* cell = pq[--pqSize];
        int height = cell[0], x = cell[1], y = cell[2];
        free(cell);

        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i], ny = y + dirs[i + 4];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx * n + ny]) {
                visited[nx * n + ny] = 1;
                result += fmax(0, height - heightMap[nx][ny]);
                int* newCell = (int*)malloc(3 * sizeof(int));
                newCell[0] = fmax(height, heightMap[nx][ny]);
                newCell[1] = nx;
                newCell[2] = ny;
                pq[pqSize++] = newCell;
                qsort(pq, pqSize, sizeof(int*), cmp);
            }
        }
    }

    free(dirs);
    for (int i = 0; i < pqSize; i++) {
        free(pq[i]);
    }
    free(pq);
    free(visited);
    return result;  
}