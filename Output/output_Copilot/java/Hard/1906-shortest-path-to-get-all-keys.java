/**https://leetcode.com/problems/shortest-path-to-get-all-keys/ */
//You are given an m x n grid grid where:
//	'.' is an empty cell.
//	'#' is a wall.
//	'@' is the starting point.
//	Lowercase letters represent keys.
//	Uppercase letters represent locks.
//You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.
//If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.
//For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.
//Return the lowest number of moves to acquire all keys. If it is impossible, return -1.
// 
//Example 1:
//Input: grid = ["@.a..","###.#","b.A.B"]
//Output: 8
//Explanation: Note that the goal is to obtain all the keys not to open all the locks.
//Example 2:
//Input: grid = ["@..aA","..B#.","....b"]
//Output: 6
//Example 3:
//Input: grid = ["@Aa"]
//Output: -1
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 30
//	grid[i][j] is either an English letter, '.', '#', or '@'. 
//	There is exactly one '@' in the grid.
//	The number of keys in the grid is in the range [1, 6].
//	Each key in the grid is unique.
//	Each key in the grid has a matching lock.
class Solution {
    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length, n = grid[0].length();
        int allKeys = 0;
        int startX = 0, startY = 0;

        // Find the starting point and calculate the bitmask for all keys
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            char c = grid[i].charAt(j);
            if (c == '@') {
                startX = i;
                startY = j;
            } else if (c >= 'a' && c <= 'f') {
                allKeys |= (1 << (c - 'a'));
            }
            }
        }

        // BFS setup
        Queue<int[]> queue = new LinkedList<>();
        boolean[][][] visited = new boolean[m][n][1 << 6];
        queue.offer(new int[]{startX, startY, 0});
        visited[startX][startY][0] = true;

        int steps = 0;
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
            int[] current = queue.poll();
            int x = current[0], y = current[1], keys = current[2];

            // If all keys are collected
            if (keys == allKeys) {
                return steps;
            }

            // Explore neighbors
            for (int[] dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                int newKeys = keys;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
                }

                char cell = grid[nx].charAt(ny);

                if (cell == '#') {
                continue; // Wall
                }

                if (cell >= 'A' && cell <= 'F' && (keys & (1 << (cell - 'A'))) == 0) {
                continue; // Lock without key
                }

                if (cell >= 'a' && cell <= 'f') {
                newKeys |= (1 << (cell - 'a')); // Collect key
                }

                if (!visited[nx][ny][newKeys]) {
                visited[nx][ny][newKeys] = true;
                queue.offer(new int[]{nx, ny, newKeys});
                }
            }
            }
            steps++;
        }

        return -1; // Impossible to collect all keys
    }   
}