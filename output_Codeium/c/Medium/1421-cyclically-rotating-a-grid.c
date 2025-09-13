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
int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize, n = *gridColSize;
    *returnSize = m;
    *returnColumnSizes = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    int** result = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            result[i][j] = grid[i][j];
        }
    }
    
    int layers = (m < n ? m : n) / 2;
    for (int layer = 0; layer < layers; layer++) {
        int top = layer, bottom = m - layer - 1;
        int left = layer, right = n - layer - 1;
        int perimeter = 2 * (bottom - top + right - left);
        
        k = k % perimeter;
        
        for (int rotation = 0; rotation < k; rotation++) {
            int temp = result[top][left];
            for (int i = left; i < right; i++)
                result[top][i] = result[top][i + 1];
            for (int i = top; i < bottom; i++)
                result[i][right] = result[i + 1][right];
            for (int i = right; i > left; i--)
                result[bottom][i] = result[bottom][i - 1];
            for (int i = bottom; i > top; i--)
                result[i][left] = result[i - 1][left];
            result[top + 1][left] = temp;
        }
    }
    
    return result;
}

