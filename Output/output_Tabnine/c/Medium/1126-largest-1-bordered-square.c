/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 9
//Example 2:
//Input: grid = [[1,1,0,0]]
//Output: 1
// 
//Constraints:
//	1 <= grid.length <= 100
//	1 <= grid[0].length <= 100
//	grid[i][j] is 0 or 1


int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize){

    int maxSide = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                int side = min(gridSize - i - 1, gridColSize[i] - j - 1);
                while (side > maxSide && allOnBorder(grid, gridSize, gridColSize, i, j, side)) {
                    maxSide = side;
                }
            }
        }
    }
    return maxSide * maxSide;
}