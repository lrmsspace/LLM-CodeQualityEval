/*
 You are given a 2D boolean matrix grid.
 A collection of 3 elements of grid is a right triangle if one of its elements is in the same row with another element and in the same column with the third element. The 3 elements may not be next to each other.
 Return an integer that is the number of right triangles that can be made with 3 elements of grid such that all of them have a value of 1.
 Example 1:
 0
 1
 0
 0
 1
 1
 0
 1
 0
 0
 1
 0
 0
 1
 1
 0
 1
 0
 0
 1
 0
 0
 1
 1
 0
 1
 0
 Input: grid = [[0,1,0],[0,1,1],[0,1,0]]
 Output: 2
 Explanation:
 There are two right triangles with elements of the value 1. Notice that the blue ones do not form a right triangle because the 3 elements are in the same column.
 Example 2:
 1
 0
 0
 0
 0
 1
 0
 1
 1
 0
 0
 0
 Input: grid = [[1,0,0,0],[0,1,0,1],[1,0,0,0]]
 Output: 0
 Explanation:
 There are no right triangles with elements of the value 1.  Notice that the blue ones do not form a right triangle.
 Example 3:
 1
 0
 1
 1
 0
 0
 1
 0
 0
 1
 0
 1
 1
 0
 0
 1
 0
 0
 Input: grid = [[1,0,1],[1,0,0],[1,0,0]]
 Output: 2
 Explanation:
 There are two right triangles with elements of the value 1.
 Constraints:
 1 <= grid.length <= 1000
 1 <= grid[i].length <= 1000
 0 <= grid[i][j] <= 1
*/

class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        long count = 0;

        // Count the number of 1s in each row and column
        int[] rowCount = new int[m];
        int[] colCount = new int[n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        // Calculate the number of right triangles
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // For each 1 at (i, j), calculate the number of pairs of 1s in the same row and column
                    count += (long)(rowCount[i] - 1) * (colCount[j] - 1);
                }
            }
        }

        return count;        
    }
}