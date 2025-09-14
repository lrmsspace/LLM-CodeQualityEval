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
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        int colors[61] = {0};
        int minRow[61] = {0};
        int maxRow[61] = {0};
        int minCol[61] = {0};
        int maxCol[61] = {0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int color = targetGrid[i][j];
                colors[color] = 1;
                minRow[color] = min(minRow[color], i);
                maxRow[color] = max(maxRow[color], i);
                minCol[color] = min(minCol[color], j);
                maxCol[color] = max(maxCol[color], j);
            }
        }
        while (true) {
            bool changed = false;
            for (int color = 1; color <= 60; color++) {
                if (colors[color] == 0) continue;
                bool canPrint = true;
                for (int i = minRow[color]; i <= maxRow[color]; i++) {
                    for (int j = minCol[color]; j <= maxCol[color]; j++) {
                        if (targetGrid[i][j] > 0 && targetGrid[i][j] != color) {
                            canPrint = false;
                            break;
                        }
                    }
                    if (!canPrint) break;
                }
                if (canPrint) {
                    changed = true;
                    colors[color] = 0;
                    for (int i = minRow[color]; i <= maxRow[color]; i++) {
                        for (int j = minCol[color]; j <= maxCol[color]; j++) {
                            targetGrid[i][j] = 0;
                        }
                    }
                }
            }
            if (!changed) break;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (targetGrid[i][j] != 0) return false;
            }
        }
        return true;      
    }
};