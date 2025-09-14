/**https://leetcode.com/problems/largest-magic-square/ */
//A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
//Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
// 
//Example 1:
//Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
//Output: 3
//Explanation: The largest magic square has a size of 3.
//Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
//- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
//- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
//- Diagonal sums: 5+4+3 = 6+4+2 = 12
//Example 2:
//Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
//Output: 2
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 106
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> row(m, vector<int>(n + 1)), col(m + 1, vector<int>(n)), diag(m + 1, vector<int>(n + 1)), anti_diag(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                anti_diag[i + 1][j] = anti_diag[i][j + 1] + grid[i][j];
            }
        }
        for (int k = min(m, n); k >= 2; --k) {
            for (int i = 0; i + k <= m; ++i) {
                for (int j = 0; j + k <= n; ++j) {
                    int sum = diag[i + k][j + k] - diag[i][j] == anti_diag[i + k][j] - anti_diag[i][j];
                    if (!sum) continue;
                    bool flag = true;
                    for (int l = 0; l < k; ++l) {
                        if (row[i + l][j + k] - row[i + l][j] != sum || col[i + k][j + l] - col[i][j + l] != sum) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) return k;
                }
            }
        }
        return 1;        
    }
};