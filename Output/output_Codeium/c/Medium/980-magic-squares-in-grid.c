/**https://leetcode.com/problems/magic-squares-in-grid/ */
//A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
//Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
// 
//Example 1:
//Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
//Output: 1
//Explanation: 
//The following subgrid is a 3 x 3 magic square:
//while this one is not:
//In total, there is only one magic square inside the given grid.
//Example 2:
//Input: grid = [[8]]
//Output: 0
// 
//Constraints:
//	row == grid.length
//	col == grid[i].length
//	1 <= row, col <= 10
//	0 <= grid[i][j] <= 15
int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int row, col;
    int sum = 45;
    for (row = 0; row < gridSize - 2; row++) {
        for (col = 0; col < *gridColSize - 2; col++) {
            int s1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
            int s2 = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2];
            int s3 = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2];
            int s4 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
            int s5 = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
            int s6 = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];
            int s7 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
            int s8 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
            if (s1 == sum && s2 == sum && s3 == sum && s4 == sum && s5 == sum && s6 == sum && s7 == sum && s8 == sum)
                count++;
        }
    }
    return count;
}