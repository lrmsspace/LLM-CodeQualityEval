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
    int m = gridSize;
    int n = gridColSize[0];
    int result = INT_MAX;
    
    // For each possible first rectangle
    for(int x1 = 0; x1 < m; x1++) {
        for(int y1 = 0; y1 < n; y1++) {
            for(int x2 = x1; x2 < m; x2++) {
                for(int y2 = y1; y2 < n; y2++) {
                    // For each possible second rectangle
                    for(int x3 = 0; x3 < m; x3++) {
                        for(int y3 = 0; y3 < n; y3++) {
                            for(int x4 = x3; x4 < m; x4++) {
                                for(int y4 = y3; y4 < n; y4++) {
                                    // For each possible third rectangle
                                    for(int x5 = 0; x5 < m; x5++) {
                                        for(int y5 = 0; y5 < n; y5++) {
                                            for(int x6 = x5; x6 < m; x6++) {
                                                for(int y6 = y5; y6 < n; y6++) {
                                                    // Check if all 1's are covered
                                                    int covered = 1;
                                                    for(int i = 0; i < m; i++) {
                                                        for(int j = 0; j < n; j++) {
                                                            if(grid[i][j] == 1) {
                                                                // Check if point is in any rectangle
                                                                int in1 = (i >= x1 && i <= x2 && j >= y1 && j <= y2);
                                                                int in2 = (i >= x3 && i <= x4 && j >= y3 && j <= y4);
                                                                int in3 = (i >= x5 && i <= x6 && j >= y5 && j <= y6);
                                                                if(!(in1 || in2 || in3)) {
                                                                    covered = 0;
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                        if(!covered) break;
                                                    }
                                                    
                                                    if(covered) {
                                                        // Calculate areas
                                                        int area1 = (x2-x1+1) * (y2-y1+1);
                                                        int area2 = (x4-x3+1) * (y4-y3+1);
                                                        int area3 = (x6-x5+1) * (y6-y5+1);
                                                        result = fmin(result, area1 + area2 + area3);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return result;
}    