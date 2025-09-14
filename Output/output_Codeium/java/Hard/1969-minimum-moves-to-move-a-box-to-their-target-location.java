/**https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/ */
//A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
//The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
//Your task is to move the box 'B' to the target position 'T' under the following rules:
//	The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
//	The character '.' represents the floor which means a free cell to walk.
//	The character '#' represents the wall which means an obstacle (impossible to walk there).
//	There is only one box 'B' and one target cell 'T' in the grid.
//	The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
//	The player cannot walk through the box.
//Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.
// 
//Example 1:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#",".","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 3
//Explanation: We return only the number of times the box is pushed.
//Example 2:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#","#","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: -1
//Example 3:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T",".",".","#","#"],
//               ["#",".","#","B",".","#"],
//               ["#",".",".",".",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 5
//Explanation: push the box down, left, left, up and up.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	grid contains only characters '.', '#', 'S', 'T', or 'B'.
//	There is only one character 'S', 'B', and 'T' in the grid.
class Solution {
    public int minPushBox(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        Queue<int[]> queue = new LinkedList<>();
        boolean[][][] visited = new boolean[m][n][4];

        int[] player = new int[2], box = new int[2], target = new int[2];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') player = new int[]{i, j};
                if (grid[i][j] == 'B') box = new int[]{i, j};
                if (grid[i][j] == 'T') target = new int[]{i, j};
            }
        }

        queue.offer(new int[]{player[0], player[1], box[0], box[1], 0});
        while (!queue.isEmpty()) {
            int[] state = queue.poll();
            int px = state[0], py = state[1], bx = state[2], by = state[3], pushes = state[4];

            if (bx == target[0] && by == target[1]) return pushes;

            for (int d = 0; d < 4; d++) {
                int nx = bx + directions[d][0], ny = by + directions[d][1];
                int pxNew = bx - directions[d][0], pyNew = by - directions[d][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#' || pxNew < 0 || pxNew >= m || pyNew < 0 || pyNew >= n || grid[pxNew][pyNew] == '#') {
                    continue;
                }

                if (!visited[bx][by][d] && canReach(grid, px, py, pxNew, pyNew, bx, by)) {
                    visited[bx][by][d] = true;
                    queue.offer(new int[]{bx, by, nx, ny, pushes + 1});
                }
            }
        }
        return -1;
    }

    private boolean canReach(char[][] grid, int px, int py, int tx, int ty, int bx, int by) {
        int m = grid.length, n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];
        queue.offer(new int[]{px, py});
        visited[px][py] = true;

        while (!queue.isEmpty()) {
            int[] pos = queue.poll();
            int x = pos[0], y = pos[1];
            if (x == tx && y == ty) return true;

            for (int[] dir : new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] != '#' && (nx != bx || ny != by)) {
                    visited[nx][ny] = true;
                    queue.offer(new int[]{nx, ny});
                }
            }
        }
        return false;   
    }
}