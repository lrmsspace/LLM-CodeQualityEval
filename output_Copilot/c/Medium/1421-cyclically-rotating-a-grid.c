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
    int m = gridSize, n = gridColSize[0];
    int** result = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(sizeof(int) * n);
    }
    int* left = (int*)malloc(sizeof(int) * m * n);
    int* right = (int*)malloc(sizeof(int) * m * n);
    int* top = (int*)malloc(sizeof(int) * m * n);
    int* bottom = (int*)malloc(sizeof(int) * m * n);
    int* temp = (int*)malloc(sizeof(int) * m * n);
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            left[index] = j;
            right[index] = j;
            top[index] = i;
            bottom[index] = i;
            temp[index++] = grid[i][j];
        }
    }
    for (int i = 0; i < m / 2 && i < n / 2; i++) {
        int len = 2 * (m - 2 * i) + 2 * (n - 2 * i) - 4;
        int offset = k % len;
        for (int j = 0; j < len; j++) {
            int next = (j + offset) % len;
            left[i * n + i + j] = i + (next < n - 2 * i ? next : n - 2 * i - 1);
            right[i * n + i + j] = i + (next < n - 2 * i ? next : n - 2 * i - 1);
            top[i * n + i + j] = i + (next < n - 2 * i ? 0 : next - n + 2 * i + 1);
            bottom[i * n + i + j] = i + (next < n - 2 * i ? 0 : next - n + 2 * i + 1);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = temp[top[i * n + j] * n + left[i * n + j]];
        }
    }
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return result;

}