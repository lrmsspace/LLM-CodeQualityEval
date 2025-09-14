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

int minMoves(char** matrix, int matrixSize) {
    int rows = matrixSize;
    int cols = strlen(matrix[0]);
    int moves = 0;

    // BFS queue
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});

    // Visited array
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    visited[0][0] = true;

    // Portal map
    std::unordered_map<char, std::vector<std::pair<int, int>>> portals;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            // If we reached the bottom-right corner
            if (x == rows - 1 && y == cols - 1) {
                return moves;
            }

            // Explore adjacent cells
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && !visited[nx][ny] && matrix[nx][ny] != '#') {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            // If we found a portal, add it to the portal map
            if (isupper(matrix[x][y])) {
                portals[matrix[x][y]].push_back({x, y});
            }
        }

        // Use portals
        for (auto& [ch, positions] : portals) {
            if (positions.size() > 1) {
                for (auto [px, py] : positions) {
                    if (!visited[px][py]) {
                        visited[px][py] = true;
                        q.push({px, py});
                    }
                }
            }
        }

        moves++;
    }

    return -1;
}