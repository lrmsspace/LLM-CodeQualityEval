/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//	On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//	Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.
// 
//Example 1:
//Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
//Output: true
//Example 2:
//Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
//Output: true
//Example 3:
//Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
//Output: false
//Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
// 
//Constraints:
//	m == targetGrid.length
//	n == targetGrid[i].length
//	1 <= m, n <= 60
//	1 <= targetGrid[row][col] <= 60
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size(), n = targetGrid[0].size();
        unordered_map<int, vector<pair<int, int>>> color;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                color[targetGrid[i][j]].push_back({i, j});
            }
        }

        for (auto &[c, v] : color) {
            int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
            for (auto [x, y] : v) {
                x1 = min(x1, x);
                y1 = min(y1, y);
                x2 = max(x2, x);
                y2 = max(y2, y);
            }
            if (x1 > x2 || y1 > y2) return false;
            for (int i = x1; i <= x2; ++i) {
                for (int j = y1; j <= y2; ++j) {
                    if (targetGrid[i][j] != c) return false;
                }
            }
        }

        return true;
    }
};