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
        vector<int> colorCount(61, 0);
        vector<int> left(m, 0), right(m, n - 1), top(n, 0), bottom(n, m - 1);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                colorCount[targetGrid[i][j]]++;
                left[i] = min(left[i], j);
                right[i] = max(right[i], j);
                top[j] = min(top[j], i);
                bottom[j] = max(bottom[j], i);
            }
        }
        
        while (!isAllColorsUsed(colorCount)) {
            int minColor = *min_element(colorCount.begin(), colorCount.end());
            for (int i = 0; i < m; ++i) {
                if (targetGrid[i][left[i]] == minColor) {
                    for (int j = left[i]; j <= right[i]; ++j) {
                        if (targetGrid[i][j] == minColor) {
                            colorCount[minColor]--;
                            targetGrid[i][j] = 0;
                            if (j == left[i]) left[i]++;
                            if (j == right[i]) right[i]--;
                            break;
                        }
                    }
                }
            }
            
            for (int j = 0; j < n; ++j) {
                if (targetGrid[top[j]][j] == minColor) {
                    for (int i = top[j]; i <= bottom[j]; ++i) {
                        if (targetGrid[i][j] == minColor) {
                            colorCount[minColor]--;
                            targetGrid[i][j] = 0;
                            if (i == top[j]) top[j]++;
                            if (i == bottom[j]) bottom[j]--;
                            break;
                        }
                    }
                }
            }
    
            if (isAllColorsUsed(colorCount)) break;
    
            minColor = *min_element(colorCount.begin(), colorCount.end());
    
            for (int i = m - 1; i >= 0; --i) {
                if (targetGrid[i][right[i]] == minColor) {
                    for (int j = right[i]; j >= left[i]; --j) {
                        if (targetGrid[i][j] == minColor) {
                            colorCount[minColor]--;
                            targetGrid[i][j] = 0;
                            if (j == right[i]) right[i]--;
                            if (j == left[i]) left[i]++;
                            break;
                        }
                    }
                }
            }
            
            for (int j = n - 1; j >= 0; --j) {

                if (targetGrid[bottom[j]][j] == minColor) {
                    for (int i = bottom[j]; i >= top[j]; --i) {
                        if (targetGrid[i][j] == minColor) {
                            colorCount[minColor]--;
                            targetGrid[i][j] = 0;
                            if (i == bottom[j]) bottom[j]--;
                            if (i == top[j]) top[j]++;
                            break;
                        }
                    }
                }
            }
            if (isAllColorsUsed(colorCount)) break;
            return false;        
    }

};