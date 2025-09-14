/*
 You are given an m x n binary matrix grid.
 A row or column is considered palindromic if its values read the same forward and backward.
 You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
 Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4.
 Example 1:
 Input: grid = [[1,0,0],[0,1,0],[0,0,1]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [[0,1],[0,1],[0,0]]
 Output: 2
 Explanation:
 Example 3:
 Input: grid = [[1],[1]]
 Output: 2
 Explanation:
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m * n <= 2 * 105
 0 <= grid[i][j] <= 1
*/

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = INT_MAX;
    
    // Try all possible combinations of flips for first half of each row
    for(int state = 0; state < (1 << (n/2)); state++) {
        vector<vector<int>> temp = grid;
        int flips = 0;
        
        // Apply flips to first half of each row
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n/2; j++) {
                if((state >> j) & 1) {
                    temp[i][j] ^= 1;
                    flips++;
                }
            }
        }
        
        // Make each row palindromic by flipping second half accordingly
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n/2; j++) {
                if(temp[i][j] != temp[i][n-1-j]) {
                    temp[i][n-1-j] = temp[i][j];
                    flips++;
                }
            }
        }
        
        // Make each column palindromic by flipping bottom half
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m/2; i++) {
                if(temp[i][j] != temp[m-1-i][j]) {
                    temp[m-1-i][j] = temp[i][j];
                    flips++;
                }
            }
        }
        
        // Count total 1s
        int ones = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ones += temp[i][j];
            }
        }
        
        // Update answer if valid
        if(ones % 4 == 0) {
            ans = min(ans, flips);
        }
    }
    
    return ans == INT_MAX ? -1 : ans;
}                
};