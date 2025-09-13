/**https://leetcode.com/problems/cyclically-rotating-a-grid/ */
//You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
//The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
//A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
//Return the matrix after applying k cyclic rotations to it.
// 
//Example 1:
//Input: grid = [[40,10],[30,20]], k = 1
//Output: [[10,20],[40,30]]
//Explanation: The figures above represent the grid at every state.
//Example 2:
//  
//Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
//Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
//Explanation: The figures above represent the grid at every state.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 50
//	Both m and n are even integers.
//	1 <= grid[i][j] <= 5000
//	1 <= k <= 109
/**

 * Return an array of arrays of size *returnSize.

 * The sizes of the arrays are returned as *returnColumnSizes array.

 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().

 */

int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){

    int m = gridSize;
    int n = gridColSize[0];
    int** result = (int**)malloc(sizeof(int*) * m);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = i;
            int y = j;
            int layer = min(min(x, y), min(m - 1 - x, n - 1 - y));
            int length = 2 * (m - 2 * layer) + 2 * (n - 2 * layer) - 4;
            int index = (k % length + length) % length;
            while (index > 0) {
                if (y == layer && x < m - 1 - layer) {
                    x++;
                } else if (x == m - 1 - layer && y < n - 1 - layer) {
                    y++;
                } else if (y == n - 1 - layer && x > layer) {
                    x--;
                } else {
                    y--;
                }
                index--;
            }
            result[i][j] = grid[x][y];
        }
    }
    return result;
}