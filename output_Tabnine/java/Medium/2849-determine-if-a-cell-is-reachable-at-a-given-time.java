/*
 You are given four integers sx, sy, fx, fy, and a non-negative integer t.
 In an infinite 2D grid, you start at the cell (sx, sy). Each second, you must move to any of its adjacent cells.
 Return true if you can reach cell (fx, fy) after exactly t seconds, or false otherwise.
 A cell's adjacent cells are the 8 cells around it that share at least one corner with it. You can visit the same cell several times.
 Example 1:
 Input: sx = 2, sy = 4, fx = 7, fy = 7, t = 6
 Output: true
 Explanation: Starting at cell (2, 4), we can reach cell (7, 7) in exactly 6 seconds by going through the cells depicted in the picture above. 
 Example 2:
 Input: sx = 3, sy = 1, fx = 7, fy = 3, t = 3
 Output: false
 Explanation: Starting at cell (3, 1), it takes at least 4 seconds to reach cell (7, 3) by going through the cells depicted in the picture above. Hence, we cannot reach cell (7, 3) at the third second.
 Constraints:
 1 <= sx, sy, fx, fy <= 109
 0 <= t <= 109
*/
class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{sx, sy, 0});
        Set<String> visited = new HashSet<>();
        visited.add(sx + "_" + sy);

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1];
            int time = current[2];

            if (x == fx && y == fy && time == t) {
                return true;
            }

            if (time < t) {
                for (int[] dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx <= 1000000000 && ny >= 0 && ny <= 1000000000 && !visited.contains(nx + "_" + ny)) {
                        queue.offer(new int[]{nx, ny, time + 1});
                        visited.add(nx + "_" + ny);
                    }
                }
            }
        }

        return false;
    }
}