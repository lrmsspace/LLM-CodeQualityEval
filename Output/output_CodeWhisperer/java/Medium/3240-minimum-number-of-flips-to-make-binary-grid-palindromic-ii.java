/*
 You are given an m x n binary matrix grid.
 A row or column is considered palindromic if its values read the same forward and backward.
 You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
 Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4.
 Example 1:
 Input: grid = [[1,0,0],[0,1,0],[0,0,1]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [[0,1],[0,1],[0,0]]
 Output: 2
 Explanation:
 Example 3:
 Input: grid = [[1],[1]]
 Output: 2
 Explanation:
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m * n <= 2 * 105
 0 <= grid[i][j] <= 1
*/

class Solution {
    public int minFlips(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;
        int[] arr = new int[m*n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                arr[i*n+j] = grid[i][j];
                count += grid[i][j];
            }
        }
        if(count == 0) return 0;
        if(count % 4 != 0) return -1;
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < m*n; i++) {
            int temp = 0;
            int[] arr1 = arr.clone();
            for(int j = 0; j < m*n; j++) {
                if(j == i) {
                    arr1[j] = arr1[j] == 0 ? 1 : 0;
                }
                else if(j == i + 1) {
                    arr1[j] = arr1[j] == 0 ? 1 : 0;
                }
                else if(j == i - 1) {
                    arr1[j] = arr1[j] == 0 ? 1 : 0;
                }
                else if(j == i + n) {
                    arr1[j] = arr1[j] == 0 ? 1 : 0;
                }
                else if(j == i - n) {
                    arr1[j] = arr1[j] == 0 ? 1 : 0;
                }
                else if(j == i + n + 1) {
                    arr1[j] = arr1[j] == 0 ? 1 : 0;
                }
                else if(j == i + n - 1) {
                    arr1[j] = arr1[j] == 0 ? 1 : 0;
                }
                else if(j == i - n + 1) {
                    arr1[j] = arr1[j] == 0 ? 1 : 0;
                }
                else if(j == i - n - 1) {
                    arr1[j] = arr1[j] == 0 ? 1 : 0;
                }
                temp += arr1[j];
            }
            if(temp < min) min = temp;
        }
        return min == Integer.MAX_VALUE ? -1 : min/2;               
    }
}