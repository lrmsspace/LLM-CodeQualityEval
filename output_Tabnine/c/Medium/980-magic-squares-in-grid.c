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
    // Magic square numbers
    int magicNumbers[] = {8, 1, 6, 3, 5, 7, 4, 9, 2};
    
    int count = 0;
    
    // Iterate through each possible top-left corner of a 3x3 subgrid
    for (int i = 0; i < gridSize - 2; i++) {
        for (int j = 0; j < gridColSize[0] - 2; j++) {
            // Check if the current subgrid forms a magic square
            if (isValidMagicSquare(grid, i, j)) {
                count++;
            }
        }
    }
    
    return count;
    
}