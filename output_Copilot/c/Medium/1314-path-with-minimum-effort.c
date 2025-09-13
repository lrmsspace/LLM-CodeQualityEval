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
    int rows = heightsSize, cols = heightsColSize[0];
    int* parent = (int*)malloc(sizeof(int) * rows * cols);
    int* rank = (int*)malloc(sizeof(int) * rows * cols);
    for (int i = 0; i < rows * cols; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    int* edges = (int*)malloc(sizeof(int) * (rows * cols * 4));
    int edgeSize = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > 0) {
                edges[edgeSize++] = (heights[i][j] - heights[i - 1][j]) * cols + i * cols + j;
            }
            if (j > 0) {
                edges[edgeSize++] = (heights[i][j] - heights[i][j - 1]) * cols + i * cols + j;
            }
        }
    }
    qsort(edges, edgeSize, sizeof(int), cmp);
    for (int i = 0; i < edgeSize; i++) {
        int edge = edges[i];
        int x = edge % cols, y = edge / cols % rows, z = edge / cols / rows;
        merge(parent, rank, x * cols + y, x * cols + y + z);
        if (find(parent, 0) == find(parent, rows * cols - 1)) {
            return z;
        }
    }
    return 0;    
}