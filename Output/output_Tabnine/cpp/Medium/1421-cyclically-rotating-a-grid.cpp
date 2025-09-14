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

public:

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int layer = min(n, m) / 2;
        int cycles = k % (2 * layer);
        for (int i = 0; i < layer; ++i, --cycles) {
            for (int j = 0; j < cycles; ++j) {
                // Swap top-left and bottom-right
                swap(grid[i][i + j], grid[n - i - 1][m - i - 1]);
                // Swap top-right and bottom-left
                swap(grid[i][m - i - 1 - j], grid[n - i - 1][i + j]);
                // Swap top and bottom
                swap(grid[i + j][i], grid[n - i - 1 - j][m - i - 1]);
                // Swap left and right
                swap(grid[n - i - 1][i + j], grid[i + j][m - i - 1]);
            }
        }
        return grid;
    }

};