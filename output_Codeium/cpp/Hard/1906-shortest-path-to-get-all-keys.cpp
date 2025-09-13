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
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x, y, k = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    x = i, y = j;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    k |= 1 << (grid[i][j] - 'a');
                }
            }
        }
        int step = 0, mask = 0;
        queue<pair<int, int>> q{{{x, y}}};
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                x = q.front().first, y = q.front().second;
                q.pop();
                if (grid[x][y] >= 'A' && grid[x][y] <= 'F' && !(mask & (1 << (grid[x][y] - 'A')))) {
                    continue;
                }
                if (grid[x][y] >= 'a' && grid[x][y] <= 'f') {
                    mask |= 1 << (grid[x][y] - 'a');
                    if (mask == k) return step;
                }
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '#') {
                        q.push({nx, ny});
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};