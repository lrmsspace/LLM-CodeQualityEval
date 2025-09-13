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
        int count = 0;
        for (int i = 0; i < grid.size() - 2; ++i) {
            for (int j = 0; j < grid[i].size() - 2; ++j) {
                if (isValid(grid, i, j)) {
                    ++count;
                }
            }
        }
        
        return count;
    }
    
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        unordered_set<int> s;
        int sum = 0;
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || s.count(val)) {
                    return false;
                }
                s.insert(val);
                sum += val;
            }
        }
        
        int target = sum / 3;
        for (int i = 0; i < 3; ++i) {
            int rowSum = 0, colSum = 0, diag1Sum = 0, diag2Sum = 0;
            for (int j = 0; j < 3; ++j) {
                rowSum += grid[x + i][y + j];
                colSum += grid[x + j][y + i];
                diag1Sum += grid[x + j][y + j];
                diag2Sum += grid[x + j][y + 2 - j];
            }
            if (rowSum != target || colSum != target || diag1Sum != target || diag2Sum != target) {
                return false;
            }
        }
        
        return true;
    }
};