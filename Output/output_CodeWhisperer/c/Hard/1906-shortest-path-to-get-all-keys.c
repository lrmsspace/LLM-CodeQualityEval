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
    int m = gridSize, n = strlen(grid[0]), key = 0, x, y;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int dp[m][n][1 << 6];
    memset(dp, -1, sizeof(dp));
    queue<int> q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '@') {
                x = i, y = j;
            } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                key++;
            }
        }
    }
    q.push(x * n * 64 + y * 64 + 0);
    dp[x][y][0] = 0;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        x = t / n / 64, y = t / 64 % n, key = t % 64;
        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] == '#') continue;
            if (grid[a][b] >= 'A' && grid[a][b] <= 'F' && !(key & (1 << (grid[a][b] - 'A')))) continue;
            int k = key;
            if (grid[a][b] >= 'a' && grid[a][b] <= 'f') k |= 1 << (grid[a][b] - 'a');
            if (dp[a][b][k] != -1) continue;
            dp[a][b][k] = dp[x][y][key] + 1;
            if (k == (1 << key) - 1) return dp[a][b][k];
            q.push(a * n * 64 + b * 64 + k);
        }
    }
    return -1;   
}