/*
 You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:
 'S': Starting position of the student
 'L': Litter that must be collected (once collected, the cell becomes empty)
 'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
 'X': Obstacle the student cannot pass through
 '.': Empty space
 You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.
 Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', which resets the energy to its maximum capacity energy.
 Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.
 Example 1:
 Input: classroom = ["S.", "XL"], energy = 2
 Output: 2
 Explanation:
 The student starts at cell (0, 0) with 2 units of energy.
 Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
 A valid sequence of moves to collect all litter is as follows:
 Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining.
 Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
 The student collects all the litter using 2 moves. Thus, the output is 2.
 Example 2:
 Input: classroom = ["LS", "RL"], energy = 4
 Output: 3
 Explanation:
 The student starts at cell (0, 1) with 4 units of energy.
 A valid sequence of moves to collect all litter is as follows:
 Move 1: From (0, 1) → (0, 0) to collect the first litter 'L' with 1 unit of energy used and 3 units remaining.
 Move 2: From (0, 0) → (1, 0) to 'R' to reset and restore energy back to 4.
 Move 3: From (1, 0) → (1, 1) to collect the second litter 'L'.
 The student collects all the litter using 3 moves. Thus, the output is 3.
 Example 3:
 Input: classroom = ["L.S", "RXL"], energy = 3
 Output: -1
 Explanation:
 No valid path collects all 'L'.
 Constraints:
 1 <= m == classroom.length <= 20
 1 <= n == classroom[i].length <= 20
 classroom[i][j] is one of 'S', 'L', 'R', 'X', or '.'
 1 <= energy <= 50
 There is exactly one 'S' in the grid.
 There are at most 10 'L' cells in the grid.
*/

int minMoves(char** classroom, int classroomSize, int energy) {
    int m = classroomSize, n = strlen(classroom[0]);
    int startX = -1, startY = -1;
    int litterCount = 0;
    int moves = 0;
    
    // Find the starting position and count the number of litter items
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (classroom[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if (classroom[i][j] == 'L') {
                litterCount++;
            }
        }
    }
    
    // Breadth-first search to find the minimum number of moves
    queue<pair<int, int>> q;
    q.push({startX, startY});
    vector<vector<int>> visited(m, vector<int>(n, 0));
    visited[startX][startY] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx][ny] == 'X' || visited[nx][ny]) continue;
                visited[nx][ny] = 1;
                if (classroom[nx][ny] == 'L') {
                    litterCount--;
                    if (litterCount == 0) return moves;
                } else if (classroom[nx][ny] == 'R') {
                    energy = energy >= 50? 50 : energy + 1;
                }
                q.push({nx, ny});
                moves++;
            }
        }
        if (energy == 0) {

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (classroom[x][y] == 'R') {
                    energy = 50;
                    break;
                }
            }
            if (energy == 0) return -1;
        }
        energy--;
        if (energy < 0) return -1;
        moves++;

        if (moves > 50 * m * n) return -1;
    }
    return -1;
    
}