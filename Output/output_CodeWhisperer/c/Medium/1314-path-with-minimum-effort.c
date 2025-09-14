/**https://leetcode.com/problems/path-with-minimum-effort/ */
//You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
//A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
//Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
// 
//Example 1:
//Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
//Output: 2
//Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
//This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
//Example 2:
//Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
//Output: 1
//Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
//Example 3:
//Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
//Output: 0
//Explanation: This route does not require any effort.
// 
//Constraints:
//	rows == heights.length
//	columns == heights[i].length
//	1 <= rows, columns <= 100
//	1 <= heights[i][j] <= 106
int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize) {
    int m = heightsSize, n = heightsColSize[0];
    int* efforts = (int*)malloc(sizeof(int) * m * n);
    for (int i = 0; i < m * n; i++) {
        efforts[i] = INT_MAX;
    }
    int* queue = (int*)malloc(sizeof(int) * m * n * 2);
    int head = 0, tail = 0;
    queue[tail++] = 0;
    queue[tail++] = 0;
    efforts[0] = 0;
    int* directions = (int*)malloc(sizeof(int) * 4);
    directions[0] = -1;
    directions[1] = 0;
    directions[2] = 1;
    directions[3] = 0;
    directions[4] = 0;
    directions[5] = -1;
    directions[6] = 0;
    directions[7] = 1;
    while (head < tail) {
        int x = queue[head++];
        int y = queue[head++];
        for (int k = 0; k < 4; k++) {
            int nx = x + directions[k * 2];
            int ny = y + directions[k * 2 + 1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int effort = (int)fabs(heights[x][y] - heights[nx][ny]);
                int max_effort = (int)fmax(effort, efforts[x * n + y]);
                if (max_effort < efforts[nx * n + ny]) {
                    efforts[nx * n + ny] = max_effort;
                    queue[tail++] = nx;
                    queue[tail++] = ny;
                }
            }
        }
    }
    int result = efforts[m * n - 1];
    free(efforts);
    free(queue);
    free(directions);
    return result;
}