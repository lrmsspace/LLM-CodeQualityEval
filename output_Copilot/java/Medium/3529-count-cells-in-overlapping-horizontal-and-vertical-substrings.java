/*
 You are given an m x n matrix grid consisting of characters and a string pattern.
 A horizontal substring is a contiguous sequence of characters read from left to right. If the end of a row is reached before the substring is complete, it wraps to the first column of the next row and continues as needed. You do not wrap from the bottom row back to the top.
 A vertical substring is a contiguous sequence of characters read from top to bottom. If the bottom of a column is reached before the substring is complete, it wraps to the first row of the next column and continues as needed. You do not wrap from the last column back to the first.
 Count the number of cells in the matrix that satisfy the following condition:
 The cell must be part of at least one horizontal substring and at least one vertical substring, where both substrings are equal to the given pattern.
 Return the count of these cells.
 Example 1:
 Input: grid = [["a","a","c","c"],["b","b","b","c"],["a","a","b","a"],["c","a","a","c"],["a","a","b","a"]], pattern = "abaca"
 Output: 1
 Explanation:
 The pattern "abaca" appears once as a horizontal substring (colored blue) and once as a vertical substring (colored red), intersecting at one cell (colored purple).
 Example 2:
 Input: grid = [["c","a","a","a"],["a","a","b","a"],["b","b","a","a"],["a","a","b","a"]], pattern = "aba"
 Output: 4
 Explanation:
 The cells colored above are all part of at least one horizontal and one vertical substring matching the pattern "aba".
 Example 3:
 Input: grid = [["a"]], pattern = "a"
 Output: 1
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m, n <= 1000
 1 <= m * n <= 105
 1 <= pattern.length <= m * n
 grid and pattern consist of only lowercase English letters.
*/

class Solution {
    public int countCells(char[][] grid, String pattern) {
        int m = grid.length;
        int n = grid[0].length;
        int patternLength = pattern.length();
        boolean[][] horizontalMatch = new boolean[m][n];
        boolean[][] verticalMatch = new boolean[m][n];

        // Check horizontal substrings
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= n - patternLength; j++) {
                boolean match = true;
                for (int k = 0; k < patternLength; k++) {
                    if (grid[i][j + k] != pattern.charAt(k)) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    for (int k = 0; k < patternLength; k++) {
                        horizontalMatch[i][j + k] = true;
                    }
                }
            }
        }

        // Check vertical substrings
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= m - patternLength; i++) {
                boolean match = true;
                for (int k = 0; k < patternLength; k++) {
                    if (grid[i + k][j] != pattern.charAt(k)) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    for (int k = 0; k < patternLength; k++) {
                        verticalMatch[i + k][j] = true;
                    }
                }
            }
        }

        // Count cells that are part of both horizontal and vertical matches
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (horizontalMatch[i][j] && verticalMatch[i][j]) {
                    count++;
                }
            }
        }

        return count;
            
    }
}