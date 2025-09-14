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
class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int count = 0;
        for (int i = 0; i < grid.length - 2; i++) {
            for (int j = 0; j < grid[i].length - 2; j++) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
        
    }

    private boolean isMagic(int[][] grid, int i, int j) {
        int[] rowSum = new int[3];
        int[] colSum = new int[3];
        int rightDiagonalSum = 0;
        int leftDiagonalSum = 0;
        Set<Integer> set = new HashSet<>();
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                int num = grid[i + k][j + l];
                rowSum[k] += num;
                colSum[l] += num;
                set.add(num);
            }
            rightDiagonalSum += grid[i + k][j + k];
            leftDiagonalSum += grid[i + k][j + 2 - k];
        }
        if (rowSum[0] != rowSum[1] || rowSum[1] != rowSum[2]) {
            return false;
        }
        if (colSum[0] != colSum[1] || colSum[1] != colSum[2]) {
            return false;
        }
        if (rightDiagonalSum != rowSum[0] || leftDiagonalSum != rowSum[0]) {
            return false;
        }
        return set.size() == 9;
    }
}