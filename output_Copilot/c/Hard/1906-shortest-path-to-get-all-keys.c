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
int shortestPathAllKeys(char** grid, int gridSize) {
       int m = gridSize, n = strlen(grid[0]);
        int target = 0, startX = 0, startY = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    target |= 1 << (grid[i][j] - 'a');
                }
            }
        }
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int*** dp = (int***)malloc(m * sizeof(int**));
        for (int i = 0; i < m; i++) {
            dp[i] = (int**)malloc(n * sizeof(int*));
            for (int j = 0; j < n; j++) {
                dp[i][j] = (int*)malloc((1 << 6) * sizeof(int));
                for (int k = 0; k < 1 << 6; k++) {
                    dp[i][j][k] = INT_MAX;
                }
            }
        }
        dp[startX][startY][0] = 0;
        int result = INT_MAX;
        int queue[3 * m * n * (1 << 6)];
        int front = 0, rear = 0;
        queue[rear++] = startX;
        queue[rear++] = startY;
        queue[rear++] = 0;
        while (front < rear) {
            int size = (rear - front) / 3;
            for (int i = 0; i < size; i++) {
                int x = queue[front++];
                int y = queue[front++];
                int state = queue[front++];
                if (state == target) {
                    result = fmin(result, dp[x][y][state]);
                }
                for (int j = 0; j < 4; j++) {
                    int newX = x + directions[j][0];
                    int newY = y + directions[j][1];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                        char c = grid[newX][newY];
                        if (c == '#') continue;
                        if (c >= 'A' && c <= 'F' && !(state & 1 << (c - 'A'))) continue;
                        int newState = state;
                        if (c >= 'a' && c <= 'f') {
                            newState |= 1 << (c - 'a');
                        }
                        if (dp[newX][newY][newState] == INT_MAX) {
                            dp[newX][newY][newState] = dp[x][y][state] + 1;
                            queue[rear++] = newX;
                            queue[rear++] = newY;
                            queue[rear++] = newState;
                        }
                    }
                    }
                }
                        }
                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < n; j++) {
                        free(dp[i][j]);
                        }
                        free(dp[i]);
                    }
                    free(dp);
                    return result == INT_MAX ? -1 : result;
}