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
    // Initialize a 2D boolean array to keep track of visited cells
    bool** visited = (bool**)calloc(1000000, sizeof(bool*));
    for (int i = 0; i < 1000000; i++) {
        visited[i] = (bool*)calloc(1000000, sizeof(bool));
    }
    // Mark the source and target cells as visited
    visited[source[0]][source[1]] = visited[target[0]][target[1]] = true;
    // Initialize a queue to store the cells to be visited
    queue<pair<int, int>> q;
    q.push({ source[0], source[1] });
    // Initialize a count variable to keep track of the number of steps
    int count = 0;
    // Initialize a set to store the coordinates of blocked cells
    set<pair<int, int>> blockedCells;
    for (int i = 0; i < blockedSize; i++) {
        blockedCells.insert({ blocked[i][0], blocked[i][1] });
    }
    // Perform BFS until the queue is empty or the target cell is reached
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // Check if the target cell is reached
            if (x == target[0] && y == target[1]) {
                free(visited);
                return true;
            }
            // Check the adjacent cells and enqueue them if they are not blocked and not visited
            if (x > 0 &&!blockedCells.count({ x - 1, y }) &&!visited[x - 1][y]) {
                visited[x - 1][y] = true;
                q.push({ x - 1, y });
            }
            if (x < 999999 &&!blockedCells.count({ x + 1, y }) &&!visited[x + 1][y]) {
                visited[x + 1][y] = true;
                q.push({ x + 1, y });
            }
            if (y > 0 &&!blockedCells.count({ x, y - 1 }) &&!visited[x][y - 1]) {
                visited[x][y - 1] = true;
                q.push({ x, y - 1 });
            }
            if (y < 999999 &&!blockedCells.count({ x, y + 1 }) &&!visited[x][y + 1]) {
                visited[x][y + 1] = true;
                q.push({ x, y + 1 });
            }
            // Increment the count variable
            count++;
            // If the count exceeds 10^6, return false
            if (count > 1000000) {
                free(visited);
                return false;
            }
        }
        // If the source cell is reached, break the loop
        if (x == source[0] && y == source[1]) {
            break;
        }
    }
    // If the queue is empty and the target cell is not reached, return false
    free(visited);
    return false;
}