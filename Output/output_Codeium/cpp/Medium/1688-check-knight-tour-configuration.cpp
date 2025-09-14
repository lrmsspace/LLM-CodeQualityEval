/**https://leetcode.com/problems/check-knight-tour-configuration/ */
//There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.
//You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.
//Return true if grid represents a valid configuration of the knight's movements or false otherwise.
//Note that a valid knight move consists of moving two squares vertically and one square horizontally, or two squares horizontally and one square vertically. The figure below illustrates all the possible eight moves of a knight from some cell.
// 
//Example 1:
//Input: grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
//Output: true
//Explanation: The above diagram represents the grid. It can be shown that it is a valid configuration.
//Example 2:
//Input: grid = [[0,3,6],[5,8,1],[2,7,4]]
//Output: false
//Explanation: The above diagram represents the grid. The 8th move of the knight is not valid considering its position after the 7th move.
// 
//Constraints:
//	n == grid.length == grid[i].length
//	3 <= n <= 7
//	0 <= grid[row][col] < n * n
//	All integers in grid are unique.
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int x = 0, y = 0, step = 0;
        vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        while (step < n * n) {
            int next = grid[x][y];
            if (next != step + 1) return false;
            step++;
            int valid = 0;
            for (auto& m : moves) {
                int nx = x + m.first, ny = y + m.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == next + 1) {
                    x = nx, y = ny;
                    valid++;
                }
            }
            if (!valid) return false;
        }
        return true;
    }
};