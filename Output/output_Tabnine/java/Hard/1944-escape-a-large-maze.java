/**https://leetcode.com/problems/escape-a-large-maze/ */
//There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
//We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
//Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid.
//Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.
// 
//Example 1:
//Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
//Output: false
//Explanation: The target square is inaccessible starting from the source square because we cannot move.
//We cannot move north or east because those squares are blocked.
//We cannot move south or west because we cannot go outside of the grid.
//Example 2:
//Input: blocked = [], source = [0,0], target = [999999,999999]
//Output: true
//Explanation: Because there are no blocked cells, it is possible to reach the target square.
// 
//Constraints:
//	0 <= blocked.length <= 200
//	blocked[i].length == 2
//	0 <= xi, yi < 106
//	source.length == target.length == 2
//	0 <= sx, sy, tx, ty < 106
//	source != target
//	It is guaranteed that source and target are not blocked.
class Solution {
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        int N = 1000000;
        boolean[][] seen = new boolean[N][N];
        seen[source[0]][source[1]] = true;
        seen[target[0]][target[1]] = true;
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(source);
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || seen[nx][ny]) continue;
                seen[nx][ny] = true;
                if (nx == target[0] && ny == target[1]) return true;
                queue.offer(new int[]{nx, ny});
            }
        }
        for (int[] b : blocked) {
            seen[b[0]][b[1]] = true;
        }
        queue.offer(target);
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || seen[nx][ny]) continue;
                seen[nx][ny] = true;
                if (nx == source[0] && ny == source[1]) return false;
                queue.offer(new int[]{nx, ny});
            }
        }
        return true;
    }
}