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
    public int minimumSum(int[][] grid) {
        int m = grid.length, n = grid[0].length, res = 0;
        boolean[][] seen = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !seen[i][j]) {
                    int area = 0, x1 = i, y1 = j, x2 = i, y2 = j;
                    Stack<int[]> stack = new Stack<>();
                    stack.push(new int[]{i, j});
                    seen[i][j] = true;
                    while (!stack.isEmpty()) {
                        int[] cur = stack.pop();
                        area++;
                        if (cur[0] > x1) x1 = cur[0];
                        if (cur[1] < y1) y1 = cur[1];
                        if (cur[0] < x2) x2 = cur[0];
                        if (cur[1] > y2) y2 = cur[1];
                        if (cur[0] > 0 && grid[cur[0] - 1][cur[1]] == 1 && !seen[cur[0] - 1][cur[1]]) {
                            stack.push(new int[]{cur[0] - 1, cur[1]});
                            seen[cur[0] - 1][cur[1]] = true;
                        }
                        if (cur[0] < m - 1 && grid[cur[0] + 1][cur[1]] == 1 && !seen[cur[0] + 1][cur[1]]) {
                            stack.push(new int[]{cur[0] + 1, cur[1]});
                            seen[cur[0] + 1][cur[1]] = true;
                        }
                        if (cur[1] > 0 && grid[cur[0]][cur[1] - 1] == 1 && !seen[cur[0]][cur[1] - 1]) {
                            stack.push(new int[]{cur[0], cur[1] - 1});
                            seen[cur[0]][cur[1] - 1] = true;
                        }
                        if (cur[1] < n - 1 && grid[cur[0]][cur[1] + 1] == 1 && !seen[cur[0]][cur[1] + 1]) {
                            stack.push(new int[]{cur[0], cur[1] + 1});
                            seen[cur[0]][cur[1] + 1] = true;
                        }
                    }
                    res += (x2 - x1 + 1) * (y2 - y1 + 1);
                }
            }
        }
        return res;
    }
}