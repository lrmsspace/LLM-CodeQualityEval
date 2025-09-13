/*
 You are given a 2D character grid matrix of size m x n, represented as an array of strings, where matrix[i][j] represents the cell at the intersection of the ith row and jth column. Each cell is one of the following:
 '.' representing an empty cell.
 '#' representing an obstacle.
 An uppercase letter ('A'-'Z') representing a teleportation portal.
 You start at the top-left cell (0, 0), and your goal is to reach the bottom-right cell (m - 1, n - 1). You can move from the current cell to any adjacent cell (up, down, left, right) as long as the destination cell is within the grid bounds and is not an obstacle.
 If you step on a cell containing a portal letter and you haven't used that portal letter before, you may instantly teleport to any other cell in the grid with the same letter. This teleportation does not count as a move, but each portal letter can be used at most once during your journey.
 Return the minimum number of moves required to reach the bottom-right cell. If it is not possible to reach the destination, return -1.
 Example 1:
 Input: matrix = ["A..",".A.","..."]
 Output: 2
 Explanation:
 Before the first move, teleport from (0, 0) to (1, 1).
 In the first move, move from (1, 1) to (1, 2).
 In the second move, move from (1, 2) to (2, 2).
 Example 2:
 Input: matrix = [".#...",".#.#.",".#.#.","...#."]
 Output: 13
 Explanation:
 Constraints:
 1 <= m == matrix.length <= 103
 1 <= n == matrix[i].length <= 103
 matrix[i][j] is either '#', '.', or an uppercase English letter.
 matrix[0][0] is not an obstacle.
*/

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> moves(m, vector<int>(n, INT_MAX));
        unordered_map<char, vector<pair<int, int>>> portals;
        queue<pair<int, int>> q;
        
        moves[0][0] = 0;
        q.push({0, 0});
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char cell = matrix[i][j];
                if (cell >= 'A' && cell <= 'Z') {
                    portals[cell].emplace_back(i, j);
                }
            }
        }
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] != '#' && moves[nx][ny] > moves[x][y] + 1) {
                    moves[nx][ny] = moves[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            
            char cell = matrix[x][y];
            if (cell >= 'A' && cell <= 'Z') {
                for (auto [px, py] : portals[cell]) {
                    if (moves[px][py] > moves[x][y]) {
                        moves[px][py] = moves[x][y];
                        q.push({px, py});
                    }
                }
                portals[cell].clear(); // Mark this portal as used
            }
        }
        
        return moves[m - 1][n - 1] == INT_MAX ? -1 : moves[m - 1][n - 1];

    }
};