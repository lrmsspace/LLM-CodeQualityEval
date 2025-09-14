/**https://leetcode.com/problems/largest-plus-sign/ */
//You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.
//Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.
//An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.
// 
//Example 1:
//Input: n = 5, mines = [[4,2]]
//Output: 2
//Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
//Example 2:
//Input: n = 1, mines = [[0,0]]
//Output: 0
//Explanation: There is no plus sign, so return 0.
// 
//Constraints:
//	1 <= n <= 500
//	1 <= mines.length <= 5000
//	0 <= xi, yi < n
//	All the pairs (xi, yi) are unique.
int orderOfLargestPlusSign(int n, int** mines, int minesSize, int* minesColSize) {
    int** grid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = n;
        }
    }

    for (int i = 0; i < minesSize; i++) {
        grid[mines[i][0]][mines[i][1]] = 0;
    }

    for (int r = 0; r < n; r++) {
        int count = 0;
        for (int c = 0; c < n; c++) {
            count = (grid[r][c] == 0) ? 0 : count + 1;
            grid[r][c] = fmin(grid[r][c], count);
        }
        count = 0;
        for (int c = n - 1; c >= 0; c--) {
            count = (grid[r][c] == 0) ? 0 : count + 1;
            grid[r][c] = fmin(grid[r][c], count);
        }
    }

    for (int c = 0; c < n; c++) {
        int count = 0;
        for (int r = 0; r < n; r++) {
            count = (grid[r][c] == 0) ? 0 : count + 1;
            grid[r][c] = fmin(grid[r][c], count);
        }
        count = 0;
        for (int r = n - 1; r >= 0; r--) {
            count = (grid[r][c] == 0) ? 0 : count + 1;
            grid[r][c] = fmin(grid[r][c], count);
        }
    }

    int maxOrder = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxOrder = fmax(maxOrder, grid[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return maxOrder;
}
        