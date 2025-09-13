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
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    zeros[i]++;
                } else {
                    break;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int target = n - 1 - i;
            int j = i;
            while (j < n && zeros[j] < target) {
                j++;
            }
            if (j == n) {
                return -1;
            }
            res += j - i;
            for (int k = j; k > i; k--) {
                zeros[k] = zeros[k - 1];
            }
        }
        return res;        
    }
};