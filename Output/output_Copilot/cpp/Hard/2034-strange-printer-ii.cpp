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
        vector<int> left(n, INT_MAX), right(n, INT_MIN), up(m, INT_MAX), down(m, INT_MIN);
        unordered_map<int, vector<int>> colors;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int color = targetGrid[i][j];
                left[color] = min(left[color], j);
                right[color] = max(right[color], j);
                up[color] = min(up[color], i);
                down[color] = max(down[color], i);
                colors[color].push_back(i * n + j);
            }
        }
        vector<vector<int>> graph(61);
        for (int i = 1; i <= 60; i++) {
            if (left[i] == INT_MAX) continue;
            for (int x = up[i]; x <= down[i]; x++) {
                for (int y = left[i]; y <= right[i]; y++) {
                    if (targetGrid[x][y] != i) {
                        graph[i].push_back(targetGrid[x][y]);
                    }
                }
            }
        }
        vector<int> visited(61);
        function<bool(int)> hasCycle = [&](int color) {
            if (visited[color] == 1) return true;
            if (visited[color] == 2) return false;
            visited[color] = 1;
            for (int next : graph[color]) {
                if (hasCycle(next)) return true;
            }
            visited[color] = 2;
            return false;
        };
        for (int i = 1; i <= 60; i++) {
            if (hasCycle(i)) return false;
        }
        return true;        
    }
};