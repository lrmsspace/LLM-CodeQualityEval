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

int minimumArea(int** grid, int gridSize, int* gridColSize) {
    int minArea = INT_MAX;
    int rows = gridSize;
    int cols = gridColSize[0];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                int maxRow = i;
                int maxCol = j;
                for (int k = i; k < rows; k++) {
                    for (int l = j; l < cols; l++) {
                        if (grid[k][l] == 1) {
                            maxRow = k;
                            maxCol = l;
                        }
                    }
                }
                
                int area = (maxRow - i + 1) * (maxCol - j + 1);
                minArea = fmin(minArea, area);
            }
        }
    }
    
    return minArea;    
}