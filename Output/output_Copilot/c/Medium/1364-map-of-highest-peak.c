/**https://leetcode.com/problems/map-of-highest-peak/ */
//You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
//	If isWater[i][j] == 0, cell (i, j) is a land cell.
//	If isWater[i][j] == 1, cell (i, j) is a water cell.
//You must assign each cell a height in a way that follows these rules:
//	The height of each cell must be non-negative.
//	If the cell is a water cell, its height must be 0.
//	Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
//Find an assignment of heights such that the maximum height in the matrix is maximized.
//Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: isWater = [[0,1],[0,0]]
//Output: [[1,0],[2,1]]
//Explanation: The image shows the assigned heights of each cell.
//The blue cell is the water cell, and the green cells are the land cells.
//Example 2:
//Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
//Output: [[1,1,0],[0,1,1],[1,2,2]]
//Explanation: A height of 2 is the maximum possible height of any assignment.
//Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
// 
//Constraints:
//	m == isWater.length
//	n == isWater[i].length
//	1 <= m, n <= 1000
//	isWater[i][j] is 0 or 1.
//	There is at least one water cell.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes) {
    int m = isWaterSize;
    int n = isWaterColSize[0];
    int** height = (int**)malloc(sizeof(int*) * m);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        height[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = m;
    int** visited = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        visited[i] = (int*)malloc(sizeof(int) * n);
        memset(visited[i], 0, sizeof(int) * n);
    }
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int max_height = 0;
    int queue[m * n][2];
    int front = 0, rear = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j] == 1) {
                height[i][j] = 0;
                visited[i][j] = 1;
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
        }
    }
    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y]) {
                height[new_x][new_y] = height[x][y] + 1;
                visited[new_x][new_y] = 1;
                queue[rear][0] = new_x;
                queue[rear][1] = new_y;
                rear++;
            }
        }
    }
    return height;    
}