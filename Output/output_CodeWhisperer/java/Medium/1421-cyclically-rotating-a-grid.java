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

        int[][] res = new int[m][n];

        for (int i = 0; i < m; i++) {

            res[i] = grid[i].clone();

        }
        int layer = Math.min(m / 2, n / 2);
        for (int i = 0; i < layer; i++) {

            int[] temp = new int[2 * (m - 2 * i) + 2 * (n - 2 * i) - 4];

            int index = 0;

            for (int j = i; j < n - i; j++) {

                temp[index++] = grid[i][j];

            }

            for (int j = i + 1; j < m - i; j++) {

                temp[index++] = grid[j][n - i - 1];

            }

            for (int j = n - i - 2; j >= i; j--) {

                temp[index++] = grid[m - i - 1][j];

            }

            for (int j = m - i - 2; j > i; j--) {

                temp[index++] = grid[j][i];

            }

            int len = temp.length;

            int kk = k % len;

            for (int j = i; j < n - i; j++) {

                res[i][j] = temp[(j - i + len - kk) % len];

            }

            for (int j = i + 1; j < m - i; j++) {

                res[j][n - i - 1] = temp[(j + n - i - 1 - i - kk + len) % len];

            }

            for (int j = n - i - 2; j >= i; j--) {

                res[m - i - 1][j] = temp[(m - i - 1 + n - j - 1 - kk + len) % len];

            }

            for (int j = m - i - 2; j > i; j--) {

                res[j][i] = temp[(m + n - 2 - i - j - 1 - kk + len) % len];

            }

        }
        return res;

    }

}