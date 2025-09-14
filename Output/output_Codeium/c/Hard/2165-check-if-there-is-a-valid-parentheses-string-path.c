/**https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/ */
//A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
//	It is ().
//	It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
//	It can be written as (A), where A is a valid parentheses string.
//You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
//	The path starts from the upper left cell (0, 0).
//	The path ends at the bottom-right cell (m - 1, n - 1).
//	The path only ever moves down or right.
//	The resulting parentheses string formed by the path is valid.
//Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.
// 
//Example 1:
//Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
//Output: true
//Explanation: The above diagram shows two possible paths that form valid parentheses strings.
//The first path shown results in the valid parentheses string "()(())".
//The second path shown results in the valid parentheses string "((()))".
//Note that there may be other valid parentheses string paths.
//Example 2:
//Input: grid = [[")",")"],["(","("]]
//Output: false
//Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 100
//	grid[i][j] is either '(' or ')'.
bool hasValidPath(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int vis[m][n];
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x == m - 1 && y == n - 1) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny] == 0) {
                if ((grid[x][y] == '(' && i == 0) || (grid[x][y] == ')' && i == 1)) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}