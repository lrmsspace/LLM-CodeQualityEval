/**https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/ */
//You are given a 2D integer array grid of size m x n, where each cell contains a positive integer.
//A cornered path is defined as a set of adjacent cells with at most one turn. More specifically, the path should exclusively move either horizontally or vertically up to the turn (if there is one), without returning to a previously visited cell. After the turn, the path will then move exclusively in the alternate direction: move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.
//The product of a path is defined as the product of all the values in the path.
//Return the maximum number of trailing zeros in the product of a cornered path found in grid.
//Note:
//	Horizontal movement means moving in either the left or right direction.
//	Vertical movement means moving in either the up or down direction.
// 
//Example 1:
//Input: grid = [[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
//Output: 3
//Explanation: The grid on the left shows a valid cornered path.
//It has a product of 15 * 20 * 6 * 1 * 10 = 18000 which has 3 trailing zeros.
//It can be shown that this is the maximum trailing zeros in the product of a cornered path.
//The grid in the middle is not a cornered path as it has more than one turn.
//The grid on the right is not a cornered path as it requires a return to a previously visited cell.
//Example 2:
//Input: grid = [[4,3,2],[7,6,1],[8,8,8]]
//Output: 0
//Explanation: The grid is shown in the figure above.
//There are no cornered paths in the grid that result in a product with a trailing zero.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	1 <= grid[i][j] <= 1000
int maxTrailingZeros(int** grid, int gridSize, int* gridColSize) {
    int result = 0;
    int m = gridSize, n = *gridColSize;
    int** dp = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        memset(dp[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp = grid[i][j];
            while (temp % 10 == 0) {
                dp[i][j]++;
                temp /= 10;
            }
        }
    }
    int** left = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        left[i] = (int*)malloc(sizeof(int) * n);
        memset(left[i], 0, sizeof(int) * n);
    }
    int** right = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        right[i] = (int*)malloc(sizeof(int) * n);
        memset(right[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            left[i][j] = j > 0 ? left[i][j - 1] + dp[i][j] : dp[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            right[i][j] = j < n - 1 ? right[i][j + 1] + dp[i][j] : dp[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int up = i > 0 ? left[i - 1][j] : 0;
            int down = i < m - 1 ? right[i + 1][j] : 0;
            int leftSum = j > 0 ? left[i][j - 1] : 0;
            int rightSum = j < n - 1 ? right[i][j + 1] : 0;
            int upSum = i > 0 ? dp[i - 1][j] : 0;
            int downSum = i < m - 1 ? dp[i + 1][j] : 0;

            int maxZeros = leftSum + upSum;
            if (leftSum + downSum > maxZeros) maxZeros = leftSum + downSum;
            if (rightSum + upSum > maxZeros) maxZeros = rightSum + upSum;
            if (rightSum + downSum > maxZeros) maxZeros = rightSum + downSum;

            if (maxZeros > result) result = maxZeros;
        }
    }

    for (int i = 0; i < m; i++) {
        free(dp[i]);
        free(left[i]);
        free(right[i]);
    }
    free(dp);
    free(left);
    free(right);

    return result;  
}