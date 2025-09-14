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
bool isEscapePossible(int** blocked, int blockedSize, int* blockedColSize, int* source, int sourceSize, int* target, int targetSize) {
    int bx[200000], by[200000];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int vis[1000001];
    int n = 0;
    for (int i = 0; i < blockedSize; i++) {
        bx[n] = blocked[i][0];
        by[n++] = blocked[i][1];
    }
    int sx = source[0], sy = source[1];
    int tx = target[0], ty = target[1];
    int dfs(int x, int y, int tx, int ty) {
        if (x == tx && y == ty) return 1;
        if (vis[x * 1000000 + y]) return 0;
        vis[x * 1000000 + y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= 1000000 || ny < 0 || ny >= 1000000) continue;
            int flag = 0;
            for (int j = 0; j < n; j++) {
                if (nx == bx[j] && ny == by[j]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag && dfs(nx, ny, tx, ty)) return 1;
        }
        return 0;
    }
    return dfs(sx, sy, tx, ty);
}   