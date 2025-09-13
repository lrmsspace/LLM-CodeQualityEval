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
class Solution {

    public int[][] rotateGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int[][] result = new int[m][n];
        int layerSize = Math.min(m, n) / 2;
        for (int layer = 0; layer < layerSize; layer++) {
            int top = layer, bottom = m - 1 - layer, left = layer, right = n - 1 - layer;
            for (int i = left; i < right; i++) {
                int temp = grid[top][i];
                grid[top][i] = grid[bottom][right];
                grid[bottom][right] = grid[bottom][left];
                grid[bottom][left] = grid[top][left];
                grid[top][left] = temp;
            }
            for (int i = top + 1; i < bottom; i++) {
                int temp = grid[i][right];
                grid[i][right] = grid[bottom][right];
                grid[bottom][right] = grid[bottom][left];
                grid[bottom][left] = grid[top][left];
                grid[top][left] = temp;
            }
            for (int i = right - 1; i > left; i--) {
                int temp = grid[bottom][i];
                grid[bottom][i] = grid[bottom][right];
                grid[bottom][right] = grid[bottom][left];
                grid[bottom][left] = grid[top][left];
                grid[top][left] = temp;
            }
    
            for (int i = left + 1; i < right; i++) {
                int temp = grid[i][left];
                grid[i][left] = grid[bottom][right];
                grid[bottom][right] = grid[bottom][left];
                grid[bottom][left] = grid[top][left];
                grid[top][left] = temp;
            }
            k = (k - 4) % (4 * layerSize);
            if (k >= 0) {
                rotate(grid, top, bottom, left, right, k);
            }
            if (k < 0) {
                rotate(grid, bottom, top, right, left, -k);
            }
            for (int i = 0; i < m; i++) {
                System.arraycopy(grid[i], 0, result[i], 0, n);
            }
            

        }
        return result;

    }

}