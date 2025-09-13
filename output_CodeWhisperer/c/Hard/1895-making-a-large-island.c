/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.
// 
//Example 1:
//Input: grid = [[1,0],[0,1]]
//Output: 3
//Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
//Example 2:
//Input: grid = [[1,1],[1,0]]
//Output: 4
//Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
//Example 3:
//Input: grid = [[1,1],[1,1]]
//Output: 4
//Explanation: Can't change any 0 to 1, only one island with area = 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 500
//	grid[i][j] is either 0 or 1.
int largestIsland(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    
    int maxArea = 0;


    int** islandId = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++) {

        islandId[i] = (int*)malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++) {

            islandId[i][j] = 0;

        }

    }

    int islandCount = 0;



    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1 && islandId[i][j] == 0) {

                islandCount++;

                int area = 0;

                int** queue = (int**)malloc(sizeof(int*) * n * n);

                int queueSize = 0;

                int queueIndex = 0;

                queue[queueSize++] = (int*)malloc(sizeof(int) * 2);

                queue[queueSize - 1][0] = i;

                queue[queueSize - 1][1] = j;

                while (queueIndex < queueSize) {

                    int x = queue[queueIndex][0];

                    int y = queue[queueIndex][1];

                    queueIndex++;

                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0 || islandId[x][y] != 0) {

                        continue;

                    }

                    islandId[x][y] = islandCount;

                    area++;

                    if (x > 0) {

                        queue[queueSize++] = (int*)malloc(sizeof(int) * 2);

                        queue[queueSize - 1][0] = x - 1;

                        queue[queueSize - 1][1] = y;

                    }

                    if (x < n - 1) {

                        queue[queueSize++] = (int*)malloc(sizeof(int) * 2);

                        queue[queueSize - 1][0] = x + 1;

                        queue[queueSize - 1][1] = y;

                    }

                    if (y > 0) {

                        queue[queueSize++] = (int*)malloc(sizeof(int) * 2);

                        queue[queueSize - 1][0] = x;

                        queue[queueSize - 1][1] = y - 1;

                    }

                    if (y < n - 1) {

                        queue[queueSize++] = (int*)malloc(sizeof(int) * 2);

                        queue[queueSize - 1][0] = x;

                        queue[queueSize - 1][1] = y + 1;

                    }

                }

                maxArea = (area > maxArea) ? area : maxArea;

            }

        }

    }
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 0) {

                int area = 1;

                int* islandSet = (int*)malloc(sizeof(int) * (islandCount + 1));

                for (int k = 0; k <= islandCount; k++) {

                    islandSet[k] = 0;

                }

                if (i > 0 && islandId[i - 1][j] != 0) {

                    islandSet[islandId[i - 1][j]] = 1;

                }

                if (i < n - 1 && islandId[i + 1][j] != 0) {

                    islandSet[islandId[i + 1][j]] = 1;

                }

                if (j > 0 && islandId[i][j - 1] != 0) {

                    islandSet[islandId[i][j - 1]] = 1;

                }

                if (j < n - 1 && islandId[i][j + 1] != 0) {

                    islandSet[islandId[i][j + 1]] = 1;

                }

                for (int k = 1; k <= islandCount; k++) {

                    if (islandSet[k] == 1) {

                        int islandArea = 0;

                        for (int x = 0; x < n; x++) {

                            for (int y = 0; y < n; y++) {

                                if (islandId[x][y] == k) {

                                    islandArea++;

                                }

                            }

                        }

                        area += islandArea;

                    }

                }

                maxArea = (area > maxArea) ? area : maxArea;

            }

        }

    }

    return maxArea;
}