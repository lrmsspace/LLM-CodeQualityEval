/**https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/ */
//Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
//A grid is said to be valid if all the cells above the main diagonal are zeros.
//Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
//The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
// 
//Example 1:
//Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
//Output: 3
//Example 2:
//Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
//Output: -1
//Explanation: All rows are similar, swaps have no effect on the grid.
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
//Output: 0
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 200
//	grid[i][j] is either 0 or 1
int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int count = 0;
    int* rowSum = (int*)malloc(n * sizeof(int));
    memset(rowSum, 0, n * sizeof(int));
    
    // Count the number of 1s in each row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rowSum[i] += grid[i][j];
        }
    }
    
    // Find the minimum number of 1s in each row
    int minCount = INT_MAX;
    for (int i = 0; i < n; i++) {
        minCount = min(minCount, rowSum[i]);
    }
    
    // Count the number of swaps needed to make each row valid
    for (int i = 0; i < n; i++) {
        count += minCount - rowSum[i];
    }
    
    free(rowSum);
    return count % 2 == 0? count / 2 : -1;
    
}