/*
 You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
 Return the minimum possible sum of the area of these rectangles.
 Note that the rectangles are allowed to touch.
 Example 1:
 Input: grid = [[1,0,1],[1,1,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
 The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 Example 2:
 Input: grid = [[1,0,1,0],[0,1,0,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 The 1 at (1, 3) is covered by a rectangle of area 1.
 Constraints:
 1 <= grid.length, grid[i].length <= 30
 grid[i][j] is either 0 or 1.
 The input is generated such that there are at least three 1's in grid.
*/

int minimumSum(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = *gridColSize;
    int minArea = n * m * 3; // Initialize to a large value
    int totalOnes = 0;

    // Count total number of ones
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                totalOnes++;
            }
        }
    }

    // If there are less than 3 ones, return -1 (invalid case)
    if (totalOnes < 3) {
        return -1;
    }

    // Iterate through all possible rectangles
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = x1 + 1; x2 <= n; x2++) {
                for (int y2 = y1 + 1; y2 <= m; y2++) {
                    int area1 = (x2 - x1) * (y2 - y1);
                    if (area1 <= 0) continue;

                    // Check if rectangle covers all ones
                    int coveredOnes = 0;
                    for (int i = x1; i < x2; i++) {
                        for (int j = y1; j < y2; j++) {
                            if (grid[i][j] == 1) {
                                coveredOnes++;
                            }
                        }
                    }

                    if (coveredOnes == totalOnes) {
                        minArea = area1;
                    }
                }
            }
        }
    }

    return minArea;    
}