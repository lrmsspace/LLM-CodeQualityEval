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
    int m = isWaterSize, n = *isWaterColSize;
    int** height = (int**)malloc(m * sizeof(int*));
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
        height[i] = (int*)malloc(n * sizeof(int));
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j] == 1) {
                height[i][j] = 0;
            } else {
                height[i][j] = INT_MAX;
            }
        }
    }
    
    for (int k = 0; k < m * n; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (height[i][j] == INT_MAX) {
                    continue;
                }
                int maxHeight = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && height[ni][nj] + 1 < height[i][j]) {
                            maxHeight = height[ni][nj] + 1;
                        }
                    }
                }
                height[i][j] = maxHeight;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (height[i][j] > height[i][j + 1]) {
                    height[i][j] = height[i][j + 1];
                }
                if (height[i][j] > height[i + 1][j]) {
                    height[i][j] = height[i + 1][j];
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (height[i][j] > height[i][j - 1]) {
                    height[i][j] = height[i][j - 1];
                }
                if (height[i][j] > height[i - 1][j]) {
                    height[i][j] = height[i - 1][j];
                }
            }
        }

    }
    
    return height;
    
}