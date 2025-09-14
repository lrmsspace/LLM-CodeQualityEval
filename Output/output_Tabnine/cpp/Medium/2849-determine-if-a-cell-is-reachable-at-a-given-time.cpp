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
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        // BFS to find the shortest path from (sx, sy) to (fx, fy) within t seconds
        queue<pair<int, int>> q;  // queue to store (x, y) coordinates
        q.push({sx, sy});
        vector<vector<int>> visited(100001, vector<int>(100001, 0));  // visited[x][y] = 1 if cell (x, y) is visited
        visited[sx][sy] = 1;
        int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};  // adjacent cells' x-coordinates
        int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};  // adjacent cells' y-coordinates
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x == fx && y == fy) {
                    return true;  // found the destination cell
                }
                if (time == t) {
                    break;  // reached the time limit
                }
                for (int j = 0; j < 8; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx >= 0 && nx <= 100000 && ny >= 0 && ny <= 100000 &&!visited[nx][ny]) {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            time++;
        }
        return false;  // destination cell not reachable within t seconds
        
    }
};