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


        #define MAX_BLOCKED 200
        #define MAX_AREA 20000

        typedef struct {
            int x, y;
        } Point;

        typedef struct {
            Point points[MAX_BLOCKED];
            int size;
        } BlockedSet;

        bool isInBlocked(BlockedSet* blockedSet, int x, int y) {
            for (int i = 0; i < blockedSet->size; i++) {
                if (blockedSet->points[i].x == x && blockedSet->points[i].y == y) {
                    return true;
                }
            }
            return false;
        }

        bool dfs(int x, int y, int tx, int ty, BlockedSet* blockedSet, bool** visited, int* area) {
            if (x < 0 || x >= 1000000 || y < 0 || y >= 1000000 || visited[x][y] || isInBlocked(blockedSet, x, y)) {
                return false;
            }
            if (x == tx && y == ty) {
                return true;
            }
            visited[x][y] = true;
            (*area)++;
            if (*area > MAX_AREA) {
                return true;
            }
            static int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (int i = 0; i < 4; i++) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                if (dfs(nx, ny, tx, ty, blockedSet, visited, area)) {
                    return true;
                }
            }
            return false;
        }

        bool isEscapePossible(int** blocked, int blockedSize, int* blockedColSize, int* source, int sourceSize, int* target, int targetSize) {
            BlockedSet blockedSet = { .size = blockedSize };
            for (int i = 0; i < blockedSize; i++) {
                blockedSet.points[i].x = blocked[i][0];
                blockedSet.points[i].y = blocked[i][1];
            }

            bool** visited = (bool**)malloc(1000000 * sizeof(bool*));
            for (int i = 0; i < 1000000; i++) {
                visited[i] = (bool*)calloc(1000000, sizeof(bool));
            }

            int area = 0;
            bool canReachSourceToTarget = dfs(source[0], source[1], target[0], target[1], &blockedSet, visited, &area);

            area = 0;
            for (int i = 0; i < 1000000; i++) {
                memset(visited[i], 0, 1000000 * sizeof(bool));
            }
            bool canReachTargetToSource = dfs(target[0], target[1], source[0], source[1], &blockedSet, visited, &area);

            for (int i = 0; i < 1000000; i++) {
                free(visited[i]);
            }
            free(visited);

            return canReachSourceToTarget && canReachTargetToSource;
        }

            