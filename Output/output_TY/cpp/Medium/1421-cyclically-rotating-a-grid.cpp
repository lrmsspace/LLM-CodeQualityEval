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
            int layer = min(n / 2, m / 2);
            for (int i = 0; i < layer; i++) {
                int x1 = i, y1 = i;
                int x2 = n - 1 - i, y2 = m - 1 - i;
                int x = x1, y = y1;
                int temp = grid[x][y];
                while (y < y2) {
                    grid[x][y] = grid[x][y + 1];
                    x = x1, y = y + 1;
                }
               while (x < x2) {
                grid[x][y] = grid[x + 1][y];
                x = x + 1, y = y2;
               }
               while (y > y1) {
                grid[x][y] = grid[x][y - 1];
                x = x2, y = y - 1;
               }
               while (x > x1) {
                grid[x][y] = grid[x - 1][y];
                x = x - 1, y = y1;
               }
               grid[x][y] = temp;
               }
               for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = (grid[i][j] + k) % 5000;
                }
               }
               return grid;
    }
};