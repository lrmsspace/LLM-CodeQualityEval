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
    public:
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            
            if (rows < 3 || cols < 3) {
                return 0;
            }
            
            int count = 0;
            
            for (int i = 0; i <= rows - 3; i++) {
                for (int j = 0; j <= cols - 3; j++) {
                    if (isMagicSquare(grid, i, j)) {
                        count++;
                    }
                }
            }
            
            return count;
        }
        
    private:
        bool isMagicSquare(const vector<vector<int>>& grid, int r, int c) {
            // Check if center is 5 (a property of standard 3x3 magic squares)
            if (grid[r + 1][c + 1] != 5) {
                return false;
            }
            
            // Check if all numbers are distinct and between 1 and 9
            unordered_set<int> nums;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = grid[r + i][c + j];
                    if (num < 1 || num > 9 || nums.count(num)) {
                        return false;
                    }
                    nums.insert(num);
                }
            }
            
            // Check rows, columns, and diagonals
            for (int i = 0; i < 3; i++) {
                if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != 15) return false; // rows
                if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != 15) return false; // columns
            }
            
            // Check diagonals
            if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15) return false; // main diagonal
            if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15) return false; // anti-diagonal
            
            return true;
        }
    };
    