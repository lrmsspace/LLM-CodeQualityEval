/*
 You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
 Return the minimum possible area of the rectangle.
 Example 1:
 Input: grid = [[0,1,0],[1,0,1]]
 Output: 6
 Explanation:
 The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
 Example 2:
 Input: grid = [[1,0],[0,0]]
 Output: 1
 Explanation:
 The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.
 Constraints:
 1 <= grid.length, grid[i].length <= 1000
 grid[i][j] is either 0 or 1.
 The input is generated such that there is at least one 1 in grid.
*/

class Solution {
    public int minimumArea(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] left = new int[m];
        int[] right = new int[m];
        int[] up = new int[n];
        int[] down = new int[n];
        for (int i = 0; i < m; i++) {
            left[i] = -1;
            right[i] = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (left[i] == -1) {
                        left[i] = j;
                    }
                    right[i] = j;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            up[j] = -1;
            down[j] = -1;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) {
                    if (up[j] == -1) {
                        up[j] = i;
                    }
                    down[j] = i;
                }
            }
        }
        int minArea = Integer.MAX_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int width = right[i] - left[i] + 1;
                    int height = down[j] - up[j] + 1;
                    minArea = Math.min(minArea, width * height);
                }
            }
        }
        return minArea;
                
    }
}