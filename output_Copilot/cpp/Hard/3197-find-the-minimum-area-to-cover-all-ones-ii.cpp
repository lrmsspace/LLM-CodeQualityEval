/*
 You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
 Return the minimum possible sum of the area of these rectangles.
 Note that the rectangles are allowed to touch.
 Example 1:
 Input: grid = [[1,0,1],[1,1,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
 The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 Example 2:
 Input: grid = [[1,0,1,0],[0,1,0,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 The 1 at (1, 3) is covered by a rectangle of area 1.
 Constraints:
 1 <= grid.length, grid[i].length <= 30
 grid[i][j] is either 0 or 1.
 The input is generated such that there are at least three 1's in grid.
*/

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));

        // Calculate prefix sums
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefixSum[i][j] = grid[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }

        int minArea = INT_MAX;

        // Iterate through all possible rectangles
        for (int r1 = 0; r1 < m; ++r1) {
            for (int c1 = 0; c1 < n; ++c1) {
                for (int r2 = r1; r2 < m; ++r2) {
                    for (int c2 = c1; c2 < n; ++c2) {
                        int area = (r2 - r1 + 1) * (c2 - c1 + 1);
                        if (area > 0 && area < minArea) {
                            int onesCount = prefixSum[r2 + 1][c2 + 1] - prefixSum[r2 + 1][c1] - prefixSum[r1][c2 + 1] + prefixSum[r1][c1];
                            if (onesCount > 0) {
                                minArea = area;
                            }
                        }
                    }
                }
            }
        }

        return minArea;
        
    }
};