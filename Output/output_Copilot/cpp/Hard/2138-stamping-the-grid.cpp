/**https://leetcode.com/problems/stamping-the-grid/ */
//You are given an m x n binary matrix grid where each cell is either 0 (empty) or 1 (occupied).
//You are then given stamps of size stampHeight x stampWidth. We want to fit the stamps such that they follow the given restrictions and requirements:
//	Cover all the empty cells.
//	Do not cover any of the occupied cells.
//	We can put as many stamps as we want.
//	Stamps can overlap with each other.
//	Stamps are not allowed to be rotated.
//	Stamps must stay completely inside the grid.
//Return true if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return false.
// 
//Example 1:
//Input: grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
//Output: true
//Explanation: We have two overlapping stamps (labeled 1 and 2 in the image) that are able to cover all the empty cells.
//Example 2:
//Input: grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
//Output: false 
//Explanation: There is no way to fit the stamps onto all the empty cells without the stamps going outside the grid.
// 
//Constraints:
//	m == grid.length
//	n == grid[r].length
//	1 <= m, n <= 105
//	1 <= m * n <= 2 * 105
//	grid[r][c] is either 0 or 1.
//	1 <= stampHeight, stampWidth <= 105
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> stamp(stampHeight, vector<int>(stampWidth, 0));
        vector<vector<int>> temp(stampHeight, vector<int>(stampWidth, 0));
        int total = 0;
        for (int i = 0; i < stampHeight; i++) {
            for (int j = 0; j < stampWidth; j++) {
                if (grid[i][j] == 1) {
                    total++;
                }
            }
        }
        while (total > 0) {
            bool found = false;
            for (int i = 0; i <= m - stampHeight; i++) {
                for (int j = 0; j <= n - stampWidth; j++) {
                    if (visited[i][j] == 0) {
                        int count = 0;
                        for (int k = 0; k < stampHeight; k++) {
                            for (int l = 0; l < stampWidth; l++) {
                                if (grid[i + k][j + l] == 1) {
                                    count++;
                                }
                            }
                        }
                        if (count == total) {
                            found = true;
                            for (int k = 0; k < stampHeight; k++) {
                                for (int l = 0; l < stampWidth; l++) {
                                    if (grid[i + k][j + l] == 1) {
                                        grid[i + k][j + l] = 0;
                                        total--;
                                    }
                                }
                            }
                            visited[i][j] = 1;
                        }
                    }
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;        
    }
};